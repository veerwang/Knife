##########################################################
#
#                    The Main project Makefile
#
# Author:    kevin.wang
# Company:
# Date:      2010.04.06
# Comment:   Acoording to the PROJ parameters to design 
#            which project to be constructed
#            
###########################################################
#SUBDIRS := $(shell find * -maxdepth 0 -path 'test' -o -path 'ggg' -prune -o -name '*' -type d -print)
SUBDIRS := $(shell find * -maxdepth 0 -type d)

.PHONY : all
all:
	@for dir in $(SUBDIRS); \
		do make -C $$dir || exit 1; \
	done

.PHONY : clean 
clean:
	@set -e;
	@for dir in $(SUBDIRS); \
		do make clean -C $$dir ||  exit 1; \
	done
