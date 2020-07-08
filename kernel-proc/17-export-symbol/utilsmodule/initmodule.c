#include<linux/init.h>  	//初始换函数
#include<linux/kernel.h>  	//内核头文件
#include<linux/module.h>  	//模块的头文件
 
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

void eddy_display_module_info(void) {
    printk(KERN_INFO "display init module infomation\n");
}

EXPORT_SYMBOL(eddy_display_module_info);
 
static int __init initmodule_start(void)
{
    printk(KERN_INFO "initmodule init\n");
    return 0;
}
 
static void __exit initmodule_end(void)
{
    printk(KERN_INFO "initmodule release\n");
}

module_init(initmodule_start);
module_exit(initmodule_end);
