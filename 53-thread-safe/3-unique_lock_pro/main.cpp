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
#include	<unistd.h>
#include 	<thread>         // std::thread
#include 	<mutex>          // std::mutex

static std::mutex mtx;           // mutex for critical section

/* 全局变量 */
static int32_t tick = 0; 

/* thread end flag */
static bool end_flag = false;

void add_thread() {
	while(!end_flag) {
		{
			mtx.lock();
			std::unique_lock<std::mutex> lcx(mtx,std::adopt_lock);
			for (int i=0;i<100;i++) {
				tick += 1;
			}
		}
		usleep(1000);
	}
}

void 
sub_thread() {
	while(!end_flag) {
		std::unique_lock<std::mutex> lcx(mtx);
		for (int i=0;i<100;i++) {
			tick -= 1;
		}
		/* 如果没有在花括号内，那么也可以采用手动的方式进行释放 */
		lcx.unlock();
		usleep(2000);
	}
}

int 
main(int argc, const char *argv[]) {
	std::cout << "mutex pro V1.0.0" << std::endl;	
  	std::thread th1 (add_thread);
  	std::thread th2 (sub_thread);

	int times = 15;
	while(times--) {
		{	// 注意此处的花括号,因为lock_guard会在活动期之后，自动释放
			std::unique_lock<std::mutex> lcx(mtx,std::defer_lock);
			// 注意 这边的std::defer_lock标志，意味着，仅仅创建lcx对象，并没有进行锁定
			// 因此还要进行手动锁定
			lcx.lock();
			printf("in main thread: tick = %d\n",tick);
			//之后使用unique_lock进行锁定，无需手动进行
			//lcx.unlock);
		}
		sleep(1);
	}
	end_flag = true;

	th1.join();
	th2.join();
	return EXIT_SUCCESS;
}
