#################################
# Created:  2020年11月09日#
#  Author:  kevin.wang		#
#################################

.PHONY: clean, mrproper
CC = gcc
CPP = g++
CFLAGS = -g -Wall -std=c++11 -I../include  -fPIE

all: main
	./main
	feh agg_test.ppm

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.cc
	$(CPP) $(CFLAGS) -c -o $@ $<

main: main.o
	$(CPP) $(CFLAGS) -o $@ $+ -L../lib -Wl,-Bstatic -lagg -Wl,-Bdynamic 

clean:
	rm -f *.o core.* *.ppm

mrproper: clean
	rm -f main
