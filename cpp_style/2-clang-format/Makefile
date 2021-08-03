#################################
# Created:  2021年08月03日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CFLAGS = -g -Wall -std=c++11

SRCS=$(wildcard *.cc *.c)
OBJS:=$(SRCS:=.o)

all: main

%.c.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.cc.o: %.cc
	$(CPP) $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f main
