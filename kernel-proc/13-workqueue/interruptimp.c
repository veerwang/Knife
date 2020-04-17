#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/interrupt.h>
#include <linux/workqueue.h>            // Required for workqueues

static char* interface = "intimp";
static int irq = 1;
void workqueue_fn(struct work_struct *work);
static int looptimes = 10;

static void workqueue_handler(struct work_struct *work) {
    printk("This is workqueue handler.. %d\n",looptimes);
    looptimes = looptimes - 1;
}

DECLARE_WORK(workqueue,workqueue_handler);

void display_version(void) {
	printk("interrupt version V2.0.0\n");
}

static irqreturn_t irq_handler(int irq,void *dev) {
	if ( looptimes != 0 )
		schedule_work(&workqueue);
        return IRQ_HANDLED;
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
