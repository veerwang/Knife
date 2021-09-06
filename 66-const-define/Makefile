#################################
# Created:  2021年09月06日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CFLAGS = -g -Wall -std=c++11

SRCS=$(wildcard *.cc *.c *.cpp)
OBJS:=$(SRCS:=.o)

all: play

%.c.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.cc.o: %.cc
	$(CPP) $(CFLAGS) -c -o $@ $<

%.cpp.o: %.cpp
	$(CPP) $(CFLAGS) -c -o $@ $<

play: $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f play
