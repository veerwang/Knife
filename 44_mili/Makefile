all: main.o object.o
	g++ -o play main.o object.o

main.o: main.cpp
	g++ -c main.cpp

object.o: object.cpp object.h
	g++ -c object.cpp

clean:
	rm -rf *.o play
