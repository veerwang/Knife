# sudo apt-get install linux-headers-$(shell uname -r)
# sudo apt-cache search linux-headers-$(uname -r)
# sudo apt-get install linux-headers-$(uname -r) 
# cat /var/log/syslog

# 固定要以.o为结尾
obj-m  	     := eddydrv.o
# 与obj-m的内容相对应
eddydrv-objs := eddydrv-main.o eddydrv-imp.o

KVERSION  = $(shell uname -r)
KERNELDIR = /usr/src/linux-headers-$(KVERSION)

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
