#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

//主设备号
#define DEV_MAJOR 224
//缓冲区大小
#define DEV_BUF_SZ 1024

//当前字符串长度
static int g_length=0;
//缓冲区
static char g_buffer[DEV_BUF_SZ];
//proc/aMsg目录
static struct proc_dir_entry* g_proc_dir;

//read操作
static ssize_t amsg_read(struct file* p_file,char* p_buf,size_t p_count,loff_t* p_offset)
{
    //最多能够读取的字节数（p_count和g_length之间较小者）
    int t_size=(p_count<g_length?p_count:g_length);
    //没有成功拷贝的字节数
    int t_rest=copy_to_user(p_buf,g_buffer,t_size);
    //不管结果如何，都清空缓冲区
    g_length=0;
    //返回成功拷贝的字节数
    return t_size-t_rest;
}

//write操作
static ssize_t amsg_write(struct file* p_file,const char* p_buf,size_t p_count,loff_t* p_offset)
{
    //最多能够写入的字节数（p_count和sizeof(g_buffer)之间较小者）
    int t_size=(p_count<sizeof(g_buffer)?p_count:sizeof(g_buffer));
    //没有成功拷贝的字节数
    int t_rest=copy_from_user(g_buffer,p_buf,t_size);
    //成功拷贝的字节数，也就是字符串的长度
    g_length=t_size-t_rest;
    //返回成功拷贝的字节数
    return g_length;
}

//填充/dev/aMsg的file_operations结构体
static struct file_operations g_amsg_fops=
{
    .owner=THIS_MODULE,
    .read=amsg_read,
    .write=amsg_write
};

//对/proc/aMsg/length的read操作
static ssize_t amsg_proc_length_read(struct file* p_file,char* p_buf,size_t p_count,loff_t* p_offset)
{
    //结果缓冲区
    char t_buf[64];
    sprintf(t_buf,"length=%d\n",g_length);
    //结果长度
    int t_length=strlen(t_buf);
    //最多能够读取的字节数（p_count和t_length之间较小者）
    int t_size=(p_count<t_length?p_count:t_length);
    //没有成功拷贝的字节数
    int t_rest=copy_to_user(p_buf,t_buf,t_size);
    //返回成功拷贝的字节数
    return t_size-t_rest;
}

//填充/proc/aMsg/length的file_operations结构体
static struct file_operations g_amsg_proc_length_fops=
{
    .owner=THIS_MODULE,
    .read=amsg_proc_length_read
};

//模块初始化代码
static int amsg_init_module(void)
{
    //注册字符设备（这是Old way）
    int t_ret=register_chrdev(DEV_MAJOR,"aMsg",&g_amsg_fops);
    //注册失败的处理
    if(t_ret<0)
    {
        printk("Unable to register\n");
        return t_ret;
    }
    //创建/proc/aMsg目录
    g_proc_dir=proc_mkdir("aMsg",0);
    if(g_proc_dir==0)
    {
        printk("Unable to mkdir /proc/aMsg\n");
        return -ENOMEM;
    }
    //创建/proc/aMsg/length文件
    struct proc_dir_entry* t_proc_length=proc_create("length",0644,g_proc_dir,&g_amsg_proc_length_fops);
    if(t_proc_length==0)
    {
        printk("Unable to create /proc/aMsg/length\n");
        return -ENOMEM;
    }
    return 0;
}

//模块清理代码
static void amsg_cleanup_module(void)
{
    //注销字符设备
    unregister_chrdev(DEV_MAJOR,"aMsg");
    //删除/proc/aMsg/length文件
    remove_proc_entry("length",g_proc_dir);
    //删除/proc/aMsg目录
    remove_proc_entry("aMsg",0);
}

module_init(amsg_init_module);
module_exit(amsg_cleanup_module);
