all: main.o status.o runstatus.o stopstatus.o
	g++ -o play main.o status.o

status.o: status.cpp status.h
	 g++ -c status.cpp

runstatus.o: runstatus.cpp runstatus.h
	 g++ -c runstatus.cpp

stopstatus.o: stopstatus.cpp stopstatus.h
	 g++ -c stopstatus.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf play *.o
