/*
 *  create by kevin
 *       2020.07.02
 */

#include "include/eddydrv.h"

/* insmod eddydrv.ko mystr=kevin  */
static char *caller = "kevin";
module_param(caller, charp, S_IRUGO);

//实现open函数
int my_misc_dev_open(struct inode *inode, struct file *filp) {
	eddydrv_info("eddydrv driver open ..");
	return 0 ;
}

//实现close函数
int my_misc_dev_close(struct inode *inode, struct file *filp) {
	eddydrv_info("eddydrv driver close ..");
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

/* ---- 对外接口 ---- */

/* 模块调用 */
char* get_caller(void) {
	return caller;
}

/* 注册 */
int do_register_stuff(void) {
	return misc_register(&my_misc_dev);
}

/* 反注册 */
void do_deregister_stuff(void) {
	misc_deregister(&my_misc_dev);
}
