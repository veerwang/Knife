#################################
# Created:  2021年08月03日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CPPFLAGS = -g -Wall -std=c++11
CFLAGS = -g -Wall

SRCS=$(wildcard *.cc *.c)
OBJS:=$(SRCS:=.o)

all: main

%.c.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.cc.o: %.cc
	$(CPP) $(CPPFLAGS) -c -o $@ $<

main: $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f main
