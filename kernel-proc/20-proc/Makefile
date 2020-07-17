# sudo apt-get install linux-headers-$(shell uname -r)
# sudo apt-cache search linux-headers-$(uname -r)
# sudo apt-get install linux-headers-$(uname -r) 
# cat /var/log/syslog

obj-m :=moduleinterface.o initmodule.o
ccflags-y := -std=gnu99 -Wno-declaration-after-statement

KVERSION  = $(shell uname -r)
KERNELDIR = /usr/src/linux-headers-$(KVERSION)

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
