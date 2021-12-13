.PHONY: clean, mrproper

CC = sdcc
CFLAGS = -mmcs51 --std-c2x

SRCS=$(wildcard *.c)
OBJS:=$(SRCS:=.rel)

all: main
	packihx main > main.hex

%.c.rel: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f  main *.rel *.sym *.lst *.asm *.lk *.ihx *.map *.mem *.rst main.hex
