all: main.o abstraction.o implementation.o
	g++ -o play main.o abstraction.o implementation.o

main.o: main.cpp
	g++ -c main.cpp

abstraction.o: abstraction.cpp abstraction.h
	g++ -c abstraction.cpp

implementation.o: implementation.cpp implementation.h
	g++ -c implementation.cpp

clean:
	rm -rf play *.o
