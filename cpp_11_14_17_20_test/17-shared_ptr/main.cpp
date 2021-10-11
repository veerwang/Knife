/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  shared_ptr使用
 *
 *        Version:  1.0
 *        Created:  2021年10月11日 
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
#include <iostream>
#include <memory>

#include "base.h"
#include "device.h"

void test1()
{
	// 重点，ptr是一个保存指针的变量，
	// 并且该指针的生命周期无需制定
	// 即无需显示释放
	std::shared_ptr<Base> ptr(new Base());
	// -> 可以访问内部的成员变量
	ptr->Display();
	// . 则是ptr这个变量的成员变量
	if (ptr.unique())
		std::cout << "it is unique" << std::endl;
	else
		std::cout << "it is not unique" << std::endl;

	std::shared_ptr<Base> tp(ptr);

	if (ptr.unique())
		std::cout << "it is unique" << std::endl;
	else
		std::cout << "it is not unique" << std::endl;

	// 将tp给清空、复位掉
	tp.reset();

	if (ptr.unique())
		std::cout << "it is unique" << std::endl;
	else
		std::cout << "it is not unique" << std::endl;
}

void test2() {
	Device device;
	device.Display();
}

int main(int argc, const char* argv[])
{
	test1();
	return EXIT_SUCCESS;
}
