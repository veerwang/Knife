/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月01日 
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
#include	<ctime>
#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init_rand
 *  Description:  初始化随机数 
 * =====================================================================================
 */
void 
init_rand() {
	// srand 随即数发射器
	// clock() 是随机种子
	srand(clock());
}

u_int32_t
get_rand(u_int32_t a,u_int32_t b) {
	return (rand() % (b-a+1))+ a;
}

int 
main(int argc, const char *argv[]) {
	std::cout << "randomic" << std::endl;

	init_rand();

	for ( int i=0;i<10;i++ ) {
		std::cout << get_rand(1,10) << std::endl;
	}

	return EXIT_SUCCESS;
}
