/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  实验C++17标准，在if与switch中声明变量
 *
 *        Version:  1.0
 *        Created:  2021年11月30日
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

// 关键语句，说明该函数建议不使用
int [[deprecated]] getValue() {
	return 10;
}

int
main(int argc, const char *argv[]) {

	if ( int value = getValue() ) {
		std::cout << value << std::endl;
	}

	return EXIT_SUCCESS;
}
