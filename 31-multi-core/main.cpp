/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年03月27日 
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

#include 	<pthread.h>
#include 	<unistd.h>
#include 	<sched.h>
#include 	<math.h>

static const char* threadmsg = "thread1";

void *thread_fun1(void *msg) {
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(3, &mask); 
        if (pthread_setaffinity_np(pthread_self(), sizeof(mask),
            &mask) < 0) {
            perror("pthread_setaffinity_np");
        }

	int times = 100;
	while( times-- ) {
		std::cout << msg << " saying.." << times << " times" << std::endl;
		sleep(1);
	}
}

void *thread_fun2(void *msg) {
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(5, &mask); 
        if (pthread_setaffinity_np(pthread_self(), sizeof(mask),
            &mask) < 0) {
            perror("pthread_setaffinity_np");
        }

	int times = 100;
	while( times-- ) {
		std::cout << msg << " saying.." << times << " times" << std::endl;
		sleep(1);
	}
}

int main(int argc, const char *argv[]) {
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(0, &mask); 
	if (sched_setaffinity(0, sizeof(mask), &mask) < 0) {
		perror("sched_setaffinity");
	}

	std::cout << "pthread create ..." << std::endl;	

	void* result;

	pthread_t thread1;
	if ( pthread_create(&thread1,NULL,&thread_fun1,(void *)threadmsg) != 0 ) {
		perror("pthread_create fail: ");
	}
	pthread_t thread2;
	if ( pthread_create(&thread2,NULL,&thread_fun2,(void *)threadmsg) != 0 ) {
		perror("pthread_create fail: ");
	}

	int times = 100;
	while( times-- ) {
		std::cout << "mainline say.." << std::endl;
		sleep(1);
	}

	pthread_join(thread1,&result);
	pthread_join(thread2,&result);
	return EXIT_SUCCESS;
}
