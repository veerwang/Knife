#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/slab.h>

#define DEVICE_NAME "miscdev_memory"

static unsigned char* k_buffer = NULL;

void 
init_internal_data(void) {
	int i;
	k_buffer = (unsigned char*)kmalloc(4096,GFP_KERNEL);
	if ( k_buffer == NULL ) {
		printk("Bad init k_buffer fail\n");
	}
	else {
		for (i=0;i<4096;i++)
			k_buffer[i] = 0;
	}
}

void
release_internal_data(void) {
	if ( k_buffer != NULL )
		kfree(k_buffer);
}

//实现read函数
static ssize_t my_misc_dev_read(struct file *filep, char __user *buf, size_t length, loff_t *offset) {
	printk("read fun: length = %ld  offset = %lld\n",length,*offset);
	return length;
}
 
//实现write数
static ssize_t my_misc_dev_write(struct file *filep, const char __user *buf, size_t length, loff_t *offset) {
	printk("write fun: length = %ld  offset = %lld\n",length,*offset);
	return length;
}

//实现open函数
static int my_misc_dev_open(struct inode *inode, struct file *filp) {
	printk("minipc misc dev open!\n");
	return 0 ;
}

//实现close函数
static int my_misc_dev_close(struct inode *inode, struct file *filp) {
	printk("minipc misc dev close!\n");
	return 0 ;
}

//初始化文件操作结构体
struct file_operations file_ops = {
	.owner	 = THIS_MODULE,
	.open	 = my_misc_dev_open,
	.release = my_misc_dev_close,
	.read    = my_misc_dev_read,
	.write   = my_misc_dev_write,
};

//初始化misc设备结构体
struct miscdevice my_misc_dev = {
	//由内核自动分配次设备号
	.minor = MISC_DYNAMIC_MINOR ,
	//初始化设备名称
	.name = DEVICE_NAME ,
	//初始化文件操作结构体
	.fops = &file_ops,	
};


static int __init my_misc_dev_init(void) {
	int ret_error ;
	//注册misc设备
	int ret = misc_register(&my_misc_dev);
	if(ret != 0){
	   ret_error = ret ;
	   printk("misc register fair!\n");
	   goto fair ;
	}
	init_internal_data();
	printk("misc init success!\n");	
	return ret ;
fair:
	return ret_error ;
}
 
static void __exit my_misc_dev_exit(void) {
	release_internal_data();
	//注销misc设备
	misc_deregister(&my_misc_dev);
	printk("misc release success!\n");	
}

module_init(my_misc_dev_init);
module_exit(my_misc_dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("kevin.wang");
