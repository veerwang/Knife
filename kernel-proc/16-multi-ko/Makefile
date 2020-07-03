# sudo apt-get install linux-headers-$(shell uname -r)
# sudo apt-cache search linux-headers-$(uname -r)
# sudo apt-get install linux-headers-$(uname -r) 
# cat /var/log/syslog

obj-m := initmodule.o newmodule.o

initmodule-y := initmain.o
newmodule-y  := newmain.o

# 编译newmain的时候，需要添加的编译开关
CFLAGS_newmain.o := -DANDROID_1

KVERSION  = $(shell uname -r)
KERNELDIR = /usr/src/linux-headers-$(KVERSION)
all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
