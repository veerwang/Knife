all: main.o subject.o concretesubject.o proxy.o
	g++ -o play main.o subject.o concretesubject.o proxy.o

main.o: main.cpp
	g++ -c main.cpp

subject.o: subject.cpp
	g++ -c subject.cpp

proxy.o: proxy.cpp
	g++ -c proxy.cpp

concretesubject.o: concretesubject.cpp
	g++ -c concretesubject.cpp

clean:
	rm -rf play *.o
