#include <linux/cdev.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/init.h> //初始换函数
#include <linux/kdev_t.h>
#include <linux/kernel.h>  //内核头文件
#include <linux/kthread.h> //kernel threads
#include <linux/module.h>  //模块的头文件
#include <linux/sched.h>   //task_struct
#include <linux/slab.h>	   //kmalloc()
#include <linux/uaccess.h> //copy_to/from_user()

static struct task_struct* etx_thread;

MODULE_LICENSE("shaohef  BSD/GPL");

int thread_function(void* pv);
/*
 * 线程函数
 */
int thread_function(void* pv)
{
	int i = 0;
	while (!kthread_should_stop()) {
		pr_info("In EmbeTronicX Thread Function %d\n", i++);
		// 休眠 1S
		msleep(1000);
	}
	return 0;
}

static int __init initmodule_start(void)
{
	etx_thread = kthread_create(thread_function, NULL, "eTx Thread");
	if (etx_thread) {
		wake_up_process(etx_thread);
	} else {
		pr_err("Cannot create kthread\n");
		goto r_device;
	}
	pr_info("Device Driver Insert...Done!!!\n");
	return 0;
r_device:
	pr_info("Create kthread fail!!!\n");
	return 0;
}

static void __exit initmodule_end(void)
{
        kthread_stop(etx_thread);
	pr_info("Device Driver Remove...Done!!\n");
}

module_init(initmodule_start);
module_exit(initmodule_end);
