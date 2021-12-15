.PHONY: clean, mrproper

CC = sdcc
CFLAGS = -mmcs51 --std-c2x

SRCS=$(wildcard *.c)
OBJS:=$(SRCS:=.rel)

all: library main
	packihx main > main.hex

library:
	@cd libs;make

%.c.rel: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	@echo library path is absolutely
	$(CC) $(CFLAGS) -L ./libs/serials/ -o $@ $+ serials.lib

clean:
	@cd libs;make clean
	rm -f  main *.rel *.sym *.lst *.asm *.lk *.ihx *.map *.mem *.rst main.hex
