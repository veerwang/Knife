/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  using替换typedef实验代码
 *
 *        Version:  1.0
 *        Created:  2021年10月08日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

void MyDisplay(int n, std::string name) {
	std::cout << "name:" << name << " n:" << n << std::endl;
}

void Test1() {
	// 定义一个Fx函数指针类型，注意Fx是一个类型
	typedef void(*Fx)(int, std::string);

	// 使用Fun类型去定义一个函数指针变量Fun，并且赋值为MyDisplay
	Fx Fun = MyDisplay;

	// 进行调用
	Fun(3, "wei");
}

void Test2() {
	// 这个是重点语句，使用using语句定义一个 void f(int, std::string)
	// 类型的函数指针的类型，注意是类型 Fy
	using Fy = void(*)(int, std::string);

	Fy Fun = MyDisplay;

	Fun(4, "veer");
}

void Test3() {
	typedef int INT_32;
	INT_32 a = 100;
	std::cout << a << std::endl;

	// 使用using替换typedef命令 
	using MYINT32 = int;
	MYINT32 b = 200;
	std::cout << b << std::endl;
}

int main(int argc, const char* argv[]) {
	Test1();
	Test2();
	Test3();	
	return EXIT_SUCCESS;
}
