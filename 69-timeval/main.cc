/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行时间参数的获取的测试 
 *
 *        Version:  1.0
 *        Created:  2021年11月01日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

void StepLoop(timeval& startp) {
	struct timeval us;

	// sys/time.h
	// 获取时间原点以来流逝的秒数与毫秒书
	gettimeofday(&us, NULL);
	std::cout << "sec:" << us.tv_sec - startp.tv_sec << std::endl;
	std::cout << "usec:" << us.tv_usec - startp.tv_usec << std::endl;
}

// 功能性的测试
void test1() {
	struct timeval startp;
	gettimeofday(&startp, NULL);

	int times = 5;
	while(times--) {
		StepLoop(startp);

		// unisted.h
		sleep(1);
	}
}

void AbilityCore() {
	uint32_t times = 10000 * 10000;
	while(times--) {
		struct timeval us;

		// sys/time.h
		// 获取时间原点以来流逝的秒数与毫秒书
		gettimeofday(&us, NULL);
	}
}

// 性能测试 
void test2() {
	struct timeval startp;
	gettimeofday(&startp, NULL);

	AbilityCore();

	struct timeval endp;
	gettimeofday(&endp, NULL);

	//std::cout << "sec:" << endp.tv_sec - startp.tv_sec << std::endl;
	//std::cout << "usec:" << endp.tv_usec - startp.tv_usec << std::endl;
	double e = static_cast<double>(endp.tv_usec - startp.tv_usec) + static_cast<double>((endp.tv_sec - startp.tv_sec) * 1000 * 1000);
	e = e / (1000 * 1000);
	std::cout << "second: " << e << std::endl;
}

int 
main(int argc, const char *argv[]) {
	test2();
	return EXIT_SUCCESS;
}
