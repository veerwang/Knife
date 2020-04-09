#include<linux/init.h>  	//初始换函数
#include<linux/kernel.h>  	//内核头文件
#include<linux/module.h>  	//模块的头文件
 
MODULE_LICENSE("GPL");

extern void display_version(void);

static int __init initmodule_start(void) {
    printk(KERN_ALERT "Loading initmodule...\n");
    display_version();
    return 0;
}
 
static void __exit initmodule_end(void) {
    printk(KERN_ALERT "initmodule release\n");
}

module_init(initmodule_start);
module_exit(initmodule_end);
