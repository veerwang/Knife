#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/serial_core.h>
#include <linux/platform_device.h>

static struct resource eddy_resource[] = {               //资源数组
    [0] = {
        .start = 0x56000050,                     //led的寄存器GPFCON起始地址
        .end   = 0x56000050 + 8 - 1,     // led的寄存器GPFDAT结束地址
        .flags = IORESOURCE_MEM,      //表示地址资源
    },
    [1] = {
        .start =  5,                                   //表示GPF第几个引脚开始
        .end   = 5,                            //结束引脚
        .flags = IORESOURCE_IRQ,     //表示中断资源    
    } 
};

static void eddy_release(struct device * dev)       //释放函数
{}

static struct platform_device eddy_dev = {
    .name         = "eddy",                    //对应的platform_driver驱动的名字 要与platform_device一样
    .id       = -1,                                    //表示只有一个设备
    .num_resources    = ARRAY_SIZE(eddy_resource),        //资源数量,ARRAY_SIZE()函数:获取数量
    .resource     = eddy_resource,      //资源数组led_resource
    .dev = {
    .release = eddy_release,                 //释放函数，必须向内核提供一个release函数, 、
                                       //否则卸载时,内核找不到该函数会报错
       },
};

static int eddy_dev_init(void)    //入口函数,注册dev设备
{
	printk("eddy device init\n");
	platform_device_register(&eddy_dev);
	return 0;
}

static void eddy_dev_exit(void) //出口函数,注销dev设备
{
	printk("eddy device exit\n");
	platform_device_unregister(&eddy_dev); 
}
module_init(eddy_dev_init);   //修饰入口函数
module_exit(eddy_dev_exit);  //修饰出口函数
MODULE_LICENSE("GPL");   //声明函数

