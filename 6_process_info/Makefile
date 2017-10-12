all:	main_server.o globalkey.o main_client.o 
	g++ -o server main_server.o globalkey.o
	g++ -o client main_client.o globalkey.o

main_server.o:	main_server.cpp processcommunication.h
	g++ -c main_server.cpp

main_client.o:	main_client.cpp processcommunication.h
	g++ -c main_client.cpp

globalkey.o:	globalkey.c
	g++ -c globalkey.c

install:
	mv server ./bin/
	mv client ./bin/
clean:
	rm -rf server client *.o bin/server bin/client
