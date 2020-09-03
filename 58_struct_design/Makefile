all: main.o Object.o
	g++ -std=c++11 -o play main.o Object.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Object.o: Object.cpp Object.h
	g++ -std=c++11 -c Object.cpp

clean:
	rm -rf *.o play compile_commands.json
