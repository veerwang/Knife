all: main.o base.o
	g++ -o play main.o base.o

main.o: main.cpp head.h
	g++ -include head.h -c main.cpp

base.o: base.cpp base.h
	g++ -include head.h -c base.cpp

clean:
	rm -rf *.o play
