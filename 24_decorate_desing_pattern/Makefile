all: main.o component.o concretecomponent.o decorator.o boarddecorator.o
	g++ -o play main.o component.o concretecomponent.o decorator.o boarddecorator.o

main.o: main.cpp
	g++ -c main.cpp

component.o: component.cpp component.h
	g++ -c component.cpp

concretecomponent.o: concretecomponent.cpp concretecomponent.h
	g++ -c concretecomponent.cpp

decorator.o: decorator.cpp decorator.h
	g++ -c decorator.cpp

boarddecorator.o: boarddecorator.cpp boarddecorator.h
	g++ -c boarddecorator.cpp

clean:
	rm -rf play *.o
