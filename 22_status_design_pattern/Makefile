all: main.o status.o runstatus.o stopstatus.o context.o
	g++ -o play main.o status.o runstatus.o stopstatus.o context.o

status.o: status.cpp status.h
	 g++ -c status.cpp

runstatus.o: runstatus.cpp runstatus.h
	 g++ -c runstatus.cpp

stopstatus.o: stopstatus.cpp stopstatus.h
	 g++ -c stopstatus.cpp

context.o: context.cpp context.h
	 g++ -c context.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf play *.o
