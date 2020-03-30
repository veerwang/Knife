#include<linux/init.h>  	//初始换函数
#include<linux/kernel.h>  	//内核头文件
#include<linux/module.h>  	//模块的头文件
#include<linux/device.h>	//class_create/device_create相关头文件的定义
				//相关头文件在KERNELDIR中有定义

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kevin.wang");

static dev_t devId;
static struct class *cls = NULL;
 
static int __init initmodule_start(void)
{
	int result;

	printk(KERN_ALERT "Loading initmodule...\n");

	// 动态申请主设备号
	//if(( result = alloc_chrdev_region(&devId, 0, 1, "stone-alloc-dev") ) != 0) {
	if(( result = alloc_chrdev_region(&devId, 0, 1, "eddy-dev") ) != 0) {
		printk(KERN_WARNING "register dev id error:%d\n", result);
		goto err;
	} else {
		printk(KERN_WARNING "register dev id success!\n");
	}

	cls = class_create(THIS_MODULE, "eddy-class");
        if(IS_ERR(cls)) {
                printk(KERN_WARNING "create class error!\n");
                goto err;
        }

	//实际在/dev目录下创建eddy%d的设备节点
        if(device_create(cls, NULL, devId, "", "eddy%d", 0) == NULL) {
                printk(KERN_WARNING "create device error!\n");
                goto err;
        }

        printk(KERN_ALERT "initmodule load success!\n");
        return 0;

err:
        device_destroy(cls, devId);
        class_destroy(cls);
        unregister_chrdev_region(devId, 1);
        return -1;
}
 
static void __exit initmodule_end(void)
{
	device_destroy(cls, devId);
	class_destroy(cls);
	unregister_chrdev_region(devId, 1);
	printk(KERN_ALERT "initmodule release\n");
}

module_init(initmodule_start);
module_exit(initmodule_end);
