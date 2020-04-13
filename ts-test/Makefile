all: main.o tsmrg.o
	g++ -o play main.o tsmrg.o

main.o: main.cpp
	g++ -c main.cpp

tsmrg.o: tsmrg.cpp tsmrg.h
	g++ -c tsmrg.cpp

clean:
	rm -rf play *.o
