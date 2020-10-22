#################################
# Created:  2020年10月22日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CFLAGS = -g -Wall -std=c++11

all: main

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.cc
	$(CPP) $(CFLAGS) -c -o $@ $<

main: main.o
	$(CPP) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f main
