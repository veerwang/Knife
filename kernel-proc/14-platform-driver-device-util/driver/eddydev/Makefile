# sudo apt-get install linux-headers-$(shell uname -r)
# sudo apt-cache search linux-headers-$(uname -r)
# sudo apt-get install linux-headers-$(uname -r) 
# cat /var/log/syslog

# ko模块的名字
obj-m := eddydev.o
eddydev-objs := eddydev-main.o


KVERSION  = $(shell uname -r)
KERNELDIR = /usr/src/linux-headers-$(KVERSION)
all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
