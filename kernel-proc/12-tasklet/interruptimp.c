#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/interrupt.h>

static char* interface = "intimp";
static int irq = 1;
static struct tasklet_struct mytasklet;

static void mytasklet_handler(unsigned long data) {
    printk("This is tasklet handler.. %d\n",data);
}

void display_version(void) {
	printk("interrupt version V1.0.0\n");
}

static irqreturn_t irq_handler(int irq,void *dev) {
	tasklet_init(&mytasklet,mytasklet_handler,1);
	tasklet_schedule(&mytasklet);
        return IRQ_NONE;
}

/* 初始化中断申请 */
int init_interrupt_request(void) {
	if(request_irq(irq,irq_handler,IRQF_SHARED,interface,&irq)) {
		return -EIO;
	}
	return 0;
}

/* 释放中断处理函数 */
void release_interrupt_request(void) {
	free_irq(irq,&irq);
}
