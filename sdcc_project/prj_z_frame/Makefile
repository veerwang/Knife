.PHONY: clean, mrproper

CC = sdcc
CFLAGS = -mmcs51 --std-c2x --model-large
TARGET = main

SRCS=$(wildcard *.c)
OBJS:=$(SRCS:=.rel)

LIBDIRS := $(shell cd modules;find * -maxdepth 0 -type d)
LIBRARIES:=$(LIBDIRS:=.lib)
LIBPATH:=$(patsubst %,-L ./modules/%/,$(LIBDIRS))

all: library $(TARGET) 
	packihx $(TARGET) > $(TARGET).hex

library:
	@cd modules;make

%.c.rel: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBPATH) -o $@ $+ $(LIBRARIES) 

clean:
	@cd modules;make clean
	rm -f  $(TARGET) *.rel *.sym *.lst *.asm *.lk *.ihx *.map *.mem *.rst $(TARGET).hex
