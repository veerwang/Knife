#include<linux/init.h>  	//初始换函数
#include<linux/kernel.h>  	//内核头文件
#include<linux/module.h>  	//模块的头文件
 
MODULE_LICENSE("GPL");

extern void display_version(void);

static int times = 0;

// 带入模块的参数
// insmod initdrv.ko times=10
module_param(times, int, S_IRUGO);

static int __init initmodule_start(void) {
    int i;
    printk(KERN_ALERT "Loading initmodule...\n");
    for ( i=0;i<times;i++  )
    	display_version();
    return 0;
}
 
static void __exit initmodule_end(void) {
    printk(KERN_ALERT "initmodule release\n");
}

module_init(initmodule_start);
module_exit(initmodule_end);
