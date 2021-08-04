#################################
# Created:  2021年08月04日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CFLAGS = -g -Wall -std=c++11 -I../include -fPIE

SRCS=$(wildcard *.cc *.c)
OBJS:=$(SRCS:=.o)

all: main
	./main
	feh agg_test.ppm

%.c.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.cc.o: %.cc
	$(CPP) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $+ -L../lib -Wl,-Bstatic -lagg -Wl,-Bdynamic 

clean:
	rm -f *.o core.* *.ppm

mrproper: clean
	rm -f main
