#include <linux/init.h>  //初始换函数
#include <linux/kernel.h>  //内核头文件
#include <linux/module.h>  //模块的头文件

/* 创建poc设备节点 */
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/proc_fs.h>
 
MODULE_LICENSE("BSD/GPL");

/* /proc目录下的设备节点 */
static struct proc_dir_entry* g_proc_dir;
static const char* drvname    = "mydrv";
static const char* subdrvname = "value";

#define DEV_BUF_SZ 10
static char g_buffer[DEV_BUF_SZ];
static int g_length = DEV_BUF_SZ;

//read操作
static ssize_t drv_read(struct file* p_file,char* p_buf,size_t p_count,loff_t* p_offset) {
    printk("enter drv_read function  %lld  %ld\n",*p_offset, p_count); 
    return 0;
    int t_size=(p_count < g_length?p_count:g_length);
    int t_rest = copy_to_user(p_buf,g_buffer,t_size);
    return t_size-t_rest;
}

static int drv_open(struct inode * mindoe, struct file *mfile) {
        printk("mydrv be open!\n");
	return 0;
}

//填充/proc/aMsg/length的file_operations结构体
static struct file_operations g_drv_proc_fops = {
    .owner = THIS_MODULE,
    .read  = drv_read,
    .open  = drv_open
};

static int __init initmodule_start(void) {
    //创建/proc/aMsg目录
    g_proc_dir=proc_mkdir(drvname,0);
    if(g_proc_dir==0) {
        printk("Unable to mkdir /proc/%s\n",drvname);
        return -ENOMEM;
    }

    struct proc_dir_entry* result = proc_create(subdrvname,0644, g_proc_dir, &g_drv_proc_fops);
    if ( result == 0 ) {
        printk("Unable to create /proc/mydrv/value\n");
        return -ENOMEM;
    }

    for (int i=0;i<DEV_BUF_SZ;i++) {
	g_buffer[i] = 0x65;
    }

    printk("proc init\n");
    return 0;
}
 
static void __exit initmodule_end(void) {
    //删除/proc/aMsg目录
    remove_proc_entry(subdrvname,g_proc_dir);
    remove_proc_entry(drvname,0);
    printk("proc end\n");
}

module_init(initmodule_start);
module_exit(initmodule_end);
