# sudo apt-get install linux-headers-$(shell uname -r)
# sudo apt-cache search linux-headers-$(uname -r)
# sudo apt-get install linux-headers-$(uname -r) 
# cat /var/log/syslog

# ko模块的名字
obj-m := drvmodule.o 
drvmodule-objs := interuptdrv.o interruptimp.o

KVERSION  = $(shell uname -r)
KERNELDIR = /usr/src/linux-headers-$(KVERSION)
all:
	make -C $(KERNELDIR) M=$(shell pwd) modules
	g++ -o play application.cpp
clean:
	make -C $(KERNELDIR) M=$(shell pwd) clean
	rm -rf *.o play
