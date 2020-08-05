all: main.o
	## 正确的方式
	g++ -o play main.o -lpthread 
	## 错误的方式
	#g++ -o play -lpthread main.o  

main.o: main.cpp
	g++ -c main.cpp -std=c++11
clean:
	rm -rf play *.o
