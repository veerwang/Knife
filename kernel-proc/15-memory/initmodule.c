#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>

/* 参考网络链接 */
// https://www.cnblogs.com/xiaojiang1025/p/6375811.html

/* 注意如果不添加这个头文件会出现问题 */
#include<linux/slab.h>		//kmalloc 函数定义

#define DEVICE_NAME "miscdev_memory"

/* 内部存储指针 */
/* 由kmalloc申请，可以被用在中断上下文中 */
static unsigned char* buffer  = NULL;

/* 使用vmalloc的函数进行申请 */
static unsigned char* vbuffer = NULL;

/* 虚拟内存长度 */
static int MAXVBUFLENGTH = 1024 * 1024;

//实现open函数
int my_misc_dev_open(struct inode *inode, struct file *filp) {
	int i = 0;
	printk("minipc misc dev open!\n");

	/* 一般 PAGE_SIZE 的长度为 4096 */
	printk("memory PAGE_SIZE = %ld!\n",PAGE_SIZE);
	/*
	GFP_USER表示为用户空间页分配内存，可以阻塞;

	GFP_KERNEL是最常用的flag，注意，使用这个flag来申请内存时，如果暂时不能满足，会引起进程阻塞，So，一定不要在中断处理函数，tasklet和内核定时器等非进程上下文中使用GFP_KERNEL！！！

	GFP_ATOMIC就可以用于上述三种情境,这个flag表示如果申请的内存不能用，则立即返回。
	*/

	/*
	flags 的参考用法： 
	　|– 进程上下文，可以睡眠　　　　　GFP_KERNEL 
	　|– 进程上下文，不可以睡眠　　　　GFP_ATOMIC 
	　|　　|– 中断处理程序　　　　　　　GFP_ATOMIC 
	　|　　|– 软中断　　　　　　　　　　GFP_ATOMIC 
	　|　　|– Tasklet　　　　　　　　　GFP_ATOMIC 
	　|– 用于DMA的内存，可以睡眠　　　GFP_DMA | GFP_KERNEL 
	　|– 用于DMA的内存，不可以睡眠　　GFP_DMA |GFP_ATOMIC 
	*/

	buffer = (unsigned char *)kmalloc(PAGE_SIZE,GFP_KERNEL);
	/* 注意使用kmalloc函数只能申请小于 PAGE_SIZE的物理连续的地址 */
	for ( i = 0; i < PAGE_SIZE; i++ ) {
		buffer[i]  = i;
	}

	/* 大内存申请，不可用于中断上下文 */
	vbuffer = (unsigned char *)vmalloc(MAXVBUFLENGTH);
	for ( i = 0; i < MAXVBUFLENGTH; i++ ) {
		vbuffer[i] = 0x55; 
	}

	printk("kernel memory virtual addr  = %p\n",buffer);

	return 0;
}

static int my_misc_dev_mmap(struct file *filp, struct vm_area_struct *vma) {
	unsigned long page; 
	unsigned long start = (unsigned long)vma->vm_start; 
	unsigned long size  = (unsigned long)(vma->vm_end - vma->vm_start); 

	//得到物理地址 
	page = virt_to_phys(buffer); 

	printk("kernel memory phisic addr  = %p \n",(void *)page);
	printk("kernel memory phisic addr >> PAGE_SHIFT  = %p \n",(void *)(page>>PAGE_SHIFT));
	//将用户空间的一个vma虚拟内存区映射到以page开始的一段连续物理页面上 
	//
	//  virtual addr: 	ffff880201774000
	//  physic  addr: 	0000000201774000
	//  page>>PAGE_SHIFT:      0000000201774
	//
	if(remap_pfn_range(vma,start,page>>PAGE_SHIFT,size,PAGE_SHARED))	//第三个参数是页帧号，由物理地址右移PAGE_SHIFT得到 
		return -1; 
	printk("[-2] %02x\n",vbuffer[MAXVBUFLENGTH-2]);
	printk("[-1] %02x\n",vbuffer[MAXVBUFLENGTH-1]);

	printk("remap finish!\n");
	return 0;
}

//实现close函数
int my_misc_dev_close(struct inode *inode, struct file *filp) {
	vfree(vbuffer);
	kfree(buffer);
	printk("minipc misc dev close!\n");
	return 0 ;
}

//初始化文件操作结构体
struct file_operations file_ops = {
	.owner	 = THIS_MODULE,
	.open	 = my_misc_dev_open,
	.release = my_misc_dev_close,
	.mmap    = my_misc_dev_mmap, 
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


static int __init my_misc_dev_init(void) {
	int ret_error ;
	//注册misc设备
	int ret = misc_register(&my_misc_dev);
	if(ret != 0){
	   ret_error = ret ;
	   printk("misc register fair!\n");
	   goto fair ;
	}
	printk("misc init success!\n");	
	return ret ;
fair:
	return ret_error ;
}
 
static void __exit my_misc_dev_exit(void) {
	//注销misc设备
	misc_deregister(&my_misc_dev);
	printk("misc exit success!\n");	
}

module_init(my_misc_dev_init);
module_exit(my_misc_dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("kevin.wang");
