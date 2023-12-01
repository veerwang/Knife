#################################
# Created:  2023年09月02日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CPPFLAGS = -g -Wall -std=c++11
CFLAGS = -g -Wall

SRCS=$(wildcard *.cc *.c *.cpp)
OBJS:=$(SRCS:=.o)

all: play

%.c.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.cc.o: %.cc
	$(CPP) $(CPPFLAGS) -c -o $@ $<

%.cpp.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

play: $(OBJS)
	$(CPP) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f play
