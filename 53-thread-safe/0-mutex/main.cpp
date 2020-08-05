/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月05日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>
#include 	<thread>         // std::thread
#include 	<mutex>          // std::mutex

static std::mutex mtx;           	 // mutex for critical section

void print_block (int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	mtx.lock();
	for (int i=0; i<n; ++i) { std::cout << c; }
	std::cout << '\n';
	mtx.unlock();
}

int 
main(int argc, const char *argv[]) {
	std::cout << "mutex pro V1.0.0" << std::endl;	
  	std::thread th1 (print_block,200,'*');
  	std::thread th2 (print_block,200,'#');
  	std::thread th3 (print_block,200,'%');

	th1.join();
	th2.join();
	th3.join();
	return EXIT_SUCCESS;
}
