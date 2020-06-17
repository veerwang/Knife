all: main.o
	g++ -std=c++11 -I/home/kevin/fmtinstall/include -L/home/kevin/fmtinstall/lib -o play main.o libfmt.a

main.o: main.cpp
	g++ -std=c++11 -I/home/kevin/fmtinstall/include -c main.cpp

clean:
	rm -rf *.o play
