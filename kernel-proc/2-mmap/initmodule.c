#include	<linux/slab.h>		//kmalloc 函数定义
#include	<linux/init.h>  	//初始换函数
#include	<linux/mm.h>  		//remap_pfn_range
#include	<asm-generic/io.h>
#include	<linux/cdev.h>
#include	<linux/fs.h>
#include	<linux/kernel.h>  	//内核头文件
#include	<linux/module.h>  	//模块的头文件
#include	<linux/device.h>	//class_create/device_create相关头文件的定义
				//相关头文件在KERNELDIR中有定义

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kevin.wang");

static dev_t devId;
static struct class *cls = NULL;
struct cdev cdev;

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char __user *, size_t, loff_t *);
static int device_mmap(struct file *, struct vm_area_struct *);

enum { MAXLENGTH = 4096 };
static unsigned char *gdatabuf;


struct file_operations eddy_fops = {
       .owner 	 = THIS_MODULE,
       .open  	 = device_open,
       .release  = device_release,
       .read     = device_read,
       .write    = device_write,
       .mmap	 = device_mmap,
};

static int device_mmap(struct file *filp, struct vm_area_struct *vma) {
	unsigned long page; 
	unsigned long start = (unsigned long)vma->vm_start; 
	//unsigned long end = (unsigned long)vma->vm_end; 
	unsigned long size = (unsigned long)(vma->vm_end - vma->vm_start); 

	//得到物理地址 
	page = virt_to_phys(gdatabuf); 
	//将用户空间的一个vma虚拟内存区映射到以page开始的一段连续物理页面上 
	if(remap_pfn_range(vma,start,page>>PAGE_SHIFT,size,PAGE_SHARED))	//第三个参数是页帧号，由物理地址右移PAGE_SHIFT得到 
		return -1; 

	gdatabuf[1] = 0x11;
	gdatabuf[2] = 0x22;
	gdatabuf[3] = 0x33;

	return 0;
}

static ssize_t device_write(struct file *mfile, const char __user *databuf, size_t mlen, loff_t *mloff) {
	int j;
	int i;
	int write_bytes;
        printk("wloff = %d!\n",(int)*mloff);
        printk("wlen = %d!\n",(int)mlen);
	write_bytes = mlen;
	if ( *mloff + mlen > MAXLENGTH ) {
		write_bytes = MAXLENGTH - *mloff;
		mlen        = MAXLENGTH - *mloff;
	}
	write_bytes = mlen;
	j = 0;
	for ( i = *mloff;i < *mloff + mlen ;i++ ) {
		gdatabuf[i] = databuf[j];
		j++;
	}

	return write_bytes;
}

static ssize_t device_read(struct file *mfile, char __user *databuf, size_t mlen, loff_t *mloff) {
	int j;
	int i;
	int read_bytes;
        printk("rloff = %d!\n",(int)*mloff);
        printk("rlen = %d!\n",(int)mlen);
	read_bytes = mlen;
	if ( *mloff + mlen > MAXLENGTH ) {
		read_bytes = MAXLENGTH - *mloff;
		mlen       = MAXLENGTH - *mloff;
	}
	read_bytes = mlen;
	j = 0;
	for ( i = *mloff;i < *mloff + mlen ;i++ ) {
		databuf[j] = gdatabuf[i];
		j++;
	}

	return read_bytes;
}

static int device_open(struct inode * mindoe, struct file *mfile) {
	int i;

	gdatabuf = (unsigned char *)kmalloc(PAGE_SIZE,GFP_KERNEL); 
	for ( i=0;i<MAXLENGTH;i++ ) {
		gdatabuf[i] = i;
	}
        printk(KERN_ALERT "initmodule be open!\n");
	return 0;
}

static int device_release(struct inode *minode, struct file *mfile) {
	kfree(gdatabuf);
        printk(KERN_ALERT "initmodule be release!\n");
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
