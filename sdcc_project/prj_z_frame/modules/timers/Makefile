.PHONY: clean, mrproper

CC = sdcc
AR = sdar
CFLAGS = -mmcs51 --std-c2x --model-large

SRCS=$(wildcard *.c)
OBJS:=$(SRCS:=.rel)

TARGET=$(shell basename $(shell pwd)).lib

all: $(TARGET) 

%.c.rel: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(AR) -rc $@ $<

clean:
	rm -f  *.lib *.rel *.sym *.lst *.asm *.lk *.ihx *.map *.mem *.rst main.hex
