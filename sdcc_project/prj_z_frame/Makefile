.PHONY: clean, mrproper

CC = sdcc
CFLAGS = -mmcs51 --std-c2x
TARGET = main

SRCS=$(wildcard *.c)
OBJS:=$(SRCS:=.rel)

LIBDIRS := $(shell cd libs;find * -maxdepth 0 -type d)
LIBRARIES:=$(LIBDIRS:=.lib)
LIBPATH:=$(patsubst %,-L ./libs/%/,$(LIBDIRS))

all: library $(TARGET) 
	packihx $(TARGET) > $(TARGET).hex

library:
	@cd libs;make

%.c.rel: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBPATH) -o $@ $+ $(LIBRARIES) 

clean:
	@cd libs;make clean
	rm -f  $(TARGET) *.rel *.sym *.lst *.asm *.lk *.ihx *.map *.mem *.rst $(TARGET).hex
