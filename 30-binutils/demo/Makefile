all:
	g++ -c -g main.cpp
	g++ -o play main.o
	rm -rf info
	mkdir info
	readelf -a play > info/all
	readelf -h play > info/head
	readelf -d play > info/dynamic
	readelf -n play > info/notice
	readelf -r play > info/relocs
	readelf -s play > info/symbols
	nm play > info/nm.symbols
	cat info/nm.symbols | c++filt > info/simple-symbols
	objdump -f play > info/arch
	objdump -j .text -S main.o > info/anti-compile 

clean:
	rm -rf play
	rm -rf info
	rm -rf *.o
