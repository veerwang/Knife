all:	main_server.o globalkey.o
	g++ -o server main_server.o globalkey.o
	g++ -o client main_client.cpp

main_server.o:	main_server.cpp
	g++ -c main_server.cpp

globalkey.o:	globalkey.c
	g++ -c globalkey.c

install:
	mv server ./bin/
	mv client ./bin/
clean:
	rm -rf server client *.o bin/server bin/client

