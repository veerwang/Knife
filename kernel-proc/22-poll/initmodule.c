#include<linux/slab.h>		//kmalloc 函数定义
#include<linux/init.h>  	//初始换函数
#include <linux/cdev.h>
#include <linux/fs.h>
#include<linux/kernel.h>  	//内核头文件
#include<linux/module.h>  	//模块的头文件
#include<linux/device.h>	//class_create/device_create相关头文件的定义
				//相关头文件在KERNELDIR中有定义

#include <linux/kdev_t.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/kthread.h>
#include <linux/wait.h>	   	//Required for the wait queues

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kevin.wang");

//Waitqueue
DECLARE_WAIT_QUEUE_HEAD(wait_queue_etx_data);

static dev_t devId;
static struct class *cls = NULL;
struct cdev cdev;

static char etx_value[20];

struct kobject* kobj_ref;

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char __user *, size_t, loff_t *);

/*************** Sysfs Fuctions **********************/
static ssize_t sysfs_show(struct kobject* kobj, struct kobj_attribute* attr, char* buf);
static ssize_t sysfs_store(struct kobject* kobj, struct kobj_attribute* attr, const char* buf, size_t count);

struct kobj_attribute etx_attr = __ATTR(etx_value, 0666, sysfs_show, sysfs_store);

struct file_operations eddy_fops = {
       .owner 	 = THIS_MODULE,
       .open  	 = device_open,
       .release  = device_release,
       .read     = device_read,
       .write    = device_write,
};

/*
** This function will be called when we read the sysfs file
*/
static ssize_t sysfs_show(struct kobject* kobj,
    struct kobj_attribute* attr,
    char* buf)
{
	pr_info("Sysfs Show - Write Permission Granted!!!\n");

	//wake up the waitqueue
	wake_up(&wait_queue_etx_data);

	return sprintf(buf, "%s", "Success\n");
}

/*
** This function will be called when we write the sysfs file
*/
static ssize_t sysfs_store(struct kobject* kobj,
    struct kobj_attribute* attr,
    const char* buf,
    size_t count)
{
	pr_info("Sysfs Store - Read Permission Granted!!!\n");

	strcpy(etx_value, buf);

	//wake up the waitqueue
	wake_up(&wait_queue_etx_data);

	return count;
}

static ssize_t device_write(struct file *mfile, const char __user *databuf, size_t mlen, loff_t *mloff) {
	return 0; 
}

static ssize_t device_read(struct file *mfile, char __user *databuf, size_t mlen, loff_t *mloff) {
	return 0; 
}

static int device_open(struct inode * mindoe, struct file *mfile) {
	return 0;
}

static int device_release(struct inode *minode, struct file *mfile) {
	return 0;
}
 
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

	// 设置设备节点的文件操作函数
	cdev_init (&cdev, &eddy_fops);
	cdev.owner = THIS_MODULE;
	cdev.ops = &eddy_fops;
	result = cdev_add (&cdev, devId , 1);
	if (result)
		printk (KERN_WARNING "Error %d adding char_reg_setup_cdev", result);

	//实际在/dev目录下创建eddy%d的设备节点
        if(device_create(cls, NULL, devId, "", "eddy%d", 0) == NULL) {
                printk(KERN_WARNING "create device error!\n");
                goto err;
        }

	/*Creating a directory in /sys/kernel/ */
	kobj_ref = kobject_create_and_add("etx_sysfs", kernel_kobj);

	/*Creating sysfs file for etx_value*/
	if (sysfs_create_file(kobj_ref, &etx_attr.attr)) {
		printk(KERN_INFO "Cannot create sysfs file......\n");
		goto r_sysfs;
	}

        printk(KERN_ALERT "initmodule load success!\n");
        return 0;

r_sysfs:
	kobject_put(kobj_ref);
	sysfs_remove_file(kernel_kobj, &etx_attr.attr);

err:
        device_destroy(cls, devId);
        class_destroy(cls);
        unregister_chrdev_region(devId, 1);
        return -1;
}
 
static void __exit initmodule_end(void)
{
	kobject_put(kobj_ref);
	sysfs_remove_file(kernel_kobj, &etx_attr.attr);

	device_destroy(cls, devId);
	class_destroy(cls);
	unregister_chrdev_region(devId, 1);
	printk(KERN_ALERT "initmodule release\n");
}

module_init(initmodule_start);
module_exit(initmodule_end);
