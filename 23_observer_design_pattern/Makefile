all: main.o observer.o subject.o concretsubject.o dogobserver.o
	g++ -o play main.o observer.o subject.o concretsubject.o dogobserver.o

main.o: main.cpp
	g++ -c main.cpp

observer.o: observer.cpp observer.h
	g++ -c observer.cpp

subject.o: subject.cpp subject.h
	g++ -c subject.cpp

concretsubject.o: concretsubject.cpp concretsubject.h
	g++ -c concretsubject.cpp

dogobserver.o: dogobserver.cpp dogobserver.h
	g++ -c dogobserver.cpp

clean:
	rm -rf play *.o
