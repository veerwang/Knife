.PHONY: clean, mrproper

CC = sdcc
CFLAGS = -mmcs51

SRCS=$(wildcard *.c)
OBJS:=$(SRCS:=.rel)

all: main

%.c.rel: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f  main *.rel *.sym *.lst *.asm *.lk *.ihx *.map *.mem *.rst
