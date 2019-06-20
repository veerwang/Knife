all: main.o component.o leaf.o composite.o
	g++ -o play main.o component.o leaf.o composite.o

leaf.o: leaf.cpp
	g++ -c leaf.cpp

component.o: component.cpp
	g++ -c component.cpp

composite.o: composite.cpp
	g++ -c composite.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf play *.o
