all: main.o adpatee.o
	g++ -o play main.o adpatee.o

main.o: main.cpp
	g++ -c main.cpp

adpatee.o: adpatee.cpp adpatee.h
	g++ -c adpatee.cpp

clean:
	rm -rf play *.o
