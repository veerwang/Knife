all:
	gcc -g -static -o play main.c
	# 注意普通情况下编译器是不会让程序在stack段进行执行的
	# 具体可以通过 readelf -f play | grep "STACK" 进行查看
	#
	#gcc -z execstack -g -static -o poc poc.c
	gcc -g -static -o poc poc.c
clean:
	rm -rf play poc
