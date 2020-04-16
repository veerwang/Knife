#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/miscdevice.h>
#include<linux/fs.h>

#define DEVICE_NAME "interruptdev"

//实现open函数
int my_misc_dev_open(struct inode *inode, struct file *filp) {
	printk("minipc misc dev open!\n");
	return 0 ;
}

//实现close函数
int my_misc_dev_close(struct inode *inode, struct file *filp) {
	printk("minipc misc dev close!\n");
	return 0 ;
}

//初始化文件操作结构体
struct file_operations file_ops = {
	.owner	 = THIS_MODULE,
	.open	 = my_misc_dev_open,
	.release = my_misc_dev_close,
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

extern void display_version(void);
extern int init_interrupt_request(void);
extern void release_interrupt_request(void);

static int __init my_misc_dev_init(void) {
	int ret_error ;
	//注册misc设备
	int ret = misc_register(&my_misc_dev);
	if(ret != 0) {
	   ret_error = ret ;
	   printk("misc register fair!\n");
	   goto fair ;
	}

	/* 显示驱动版本 */
	display_version();
	if ( init_interrupt_request() != 0 )
		goto fair;

	printk("misc init success!\n");	
	return ret ;
fair:
	return ret_error ;
}
 
static void __exit my_misc_dev_exit(void) {
	release_interrupt_request();
	//注销misc设备
	misc_deregister(&my_misc_dev);
}

module_init(my_misc_dev_init);
module_exit(my_misc_dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("kevin.wang");
