all: main.o uclmrg.o
	g++ -std=c++11 -o play main.o uclmrg.o -std=c++11 -L/home/kevin/libucl/lib -lucl

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -I/home/kevin/libucl/include 

uclmrg.o: uclmrg.cpp uclmrg.h
	g++ -std=c++11 -c uclmrg.cpp -I/home/kevin/libucl/include 

clean:
	rm -rf play *.o
