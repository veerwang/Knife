/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月24日 
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

/* 显示数据 */
void display() {
	int times = 3;

	/* lambda函数, 开始于[],结束于{},注意要有分号 */
	/* 使用场景用于并非一定要函数的地方 */
	auto f = [](int times) {
		for (int i = 0; i < times; i++) {
			std::cout << "display" << std::endl;
		}
	}; 	// 注意分号

	/* std=c++14 支持 */
	auto add = [](auto a,auto b) {
		return a + b;
	};

	f(times);

	f(2);

	std::cout << add(10,20) << std::endl;
}

int main(int argc, const char *argv[])
{
	std::cout << "lambda V1.0.0" << std::endl;	

	display();

	return EXIT_SUCCESS;
}