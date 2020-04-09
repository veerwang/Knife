#include<linux/init.h>  	//初始换函数
#include<linux/kernel.h>  	//内核头文件
#include<linux/module.h>  	//模块的头文件

void display_version(void) {
    printk(KERN_ALERT "kernel module version: V2.0.0...\n");
}
