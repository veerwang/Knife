# sudo apt-get install linux-headers-$(shell uname -r)
# sudo apt-cache search linux-headers-$(uname -r)
# sudo apt-get install linux-headers-$(uname -r) 
# cat /var/log/syslog

# ko模块的名字
obj-m := miscdrv.o 
miscdrv-objs := initmodule.o

KVERSION  = $(shell uname -r)
KERNELDIR = /usr/src/linux-headers-$(KVERSION)

# 注意一定要绝对路径,或者将其他模块的*.symvers复制到当前目录进行编译
#KBUILD_EXTRA_SYMBOLS = /mnt/github.com/Knife/kernel-proc/17-export-symbol/utilsmodule/Module.symvers

#如果不添加KBUILD_EXTRA_SYMBOLS
#直接将Module.symvers文件添加到该驱动的目录之下

all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
