#################################
# Created:  2021年06月08日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CFLAGS = -g -Wall -std=c++11

all: play

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.cc
	$(CPP) $(CFLAGS) -c -o $@ $<

play: main.o basic.o
	$(CPP) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f play
