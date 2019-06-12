all: main.o observer.o subject.o
	g++ -o play main.o observer.o subject.o

main.o: main.cpp
	g++ -c main.cpp

observer.o: observer.cpp observer.h
	g++ -c observer.cpp

subject.o: subject.cpp subject.h
	g++ -c subject.cpp

clean:
	rm -rf play *.o
