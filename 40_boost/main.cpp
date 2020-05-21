/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月21日 
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

#include 	<boost/thread.hpp>

static bool thread_finish_flag = false;

void thread_process() {
	int i = 10;
	while( i ) {
		std::cout << "thread ... " << i << std::endl;
		i --;
		sleep(1);
	};
	thread_finish_flag = true;
}

int main(int argc, const char *argv[]) {
	std::cout << "boost program" << std::endl;	
	boost::thread t(thread_process);

	while(!thread_finish_flag) {
		std::cout << "main ... " << std::endl;
		sleep(2);
	}

	/* 等待线程退出 */
	t.join();
	return EXIT_SUCCESS;
}
