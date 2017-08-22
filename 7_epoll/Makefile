all:	main_server.o
	g++ -o server main_server.o
	g++ -o client main_client.cpp

main_server.o:	main_server.cpp
	g++ -c main_server.cpp

install:
	mv server ./bin/
	mv client ./bin/
clean:
	rm -rf server client *.o bin/server bin/client
