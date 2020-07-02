#ifndef INCLUDED_EDDYDRV_H
#define INCLUDED_EDDYDRV_H

#include <linux/init.h>    	//初始换函数
#include <linux/kernel.h>  	//内核头文件
#include <linux/module.h>  	//模块的头文件
#include <linux/device.h>  
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>

/*
#define KERN_EMERG     "<0>"
#define KERN_ALERT     "<1>"
#define KERN_CRIT      "<2>"
#define KERN_ERR       "<3>"
#define KERN_WARNING   "<4>"
#define KERN_NOTICE    "<5>"
#define KERN_INFO      "<6>"
#define KERN_DEBUG     "<7>"
级别越小，越紧急
*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kevin.wang");
MODULE_DESCRIPTION("eddy project practice for platform driver and device");

#define MODULE_NAME  "eddydrv"
#define DEVICE_NAME  MODULE_NAME
#define DRIVER_NAME  MODULE_NAME

#define __FILENAME__  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define eddydrv_info(fmt, ...) printk(KERN_INFO MODULE_NAME ": %s: %s: %d: " fmt, __FILENAME__, __func__, __LINE__, ## __VA_ARGS__)

#define eddydrv_err(fmt, ...) printk(KERN_ERR MODULE_NAME ": %s: %s: %d: " fmt, __FILENAME__, __func__, __LINE__, ## __VA_ARGS__)

#define eddydrv_warning(fmt, ...) printk(KERN_WARNING MODULE_NAME ": %s: %s: %d: " fmt, __FILENAME__, __func__, __LINE__, ## __VA_ARGS__)



/* 来源eddydrv-imp模块*/
extern char* get_caller(void);
extern int do_register_stuff(void);
extern void do_deregister_stuff(void);

#endif /* INCLUDED_EDDYDRV_H */
