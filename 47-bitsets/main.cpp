/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年07月10日 
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
#include	<bitset>

int main(int argc, const char *argv[]) {
	std::cout << "bitsets test V1.0.0" << std::endl;

	/* 初始化 */
	std::bitset<8> controlReg(0xf0);
	/* 确认位数 */
	std::cout << "size: " << controlReg.size() << std::endl;

	/* 访问各个位数 */
	for (int i = 0; i < controlReg.size(); i++) {
		std::cout << controlReg[i] << std::endl;	
		if ( controlReg[i] == 1 ) {
			std::cout << "Good" << std::endl;
		}
	}

	std::cout << "---------" << std::endl;

	/* 第0位，清除 */
	controlReg.reset(0);
	/* 第2位，清除 */
	controlReg.reset(2);

	/* 第0位，置位 */
	controlReg.set(0);

	/* 第5位，取反 */
	controlReg.flip(5);

	for (int i = 0; i < controlReg.size(); i++) {
		std::cout << controlReg[i] << std::endl;	
	}

	/* 有几个1 */
	std::cout << "reg 1 has:" << controlReg.count()<< std::endl;

	std::cout << "---------" << std::endl;

	u_int8_t value = 0x5a;
	std::bitset<8> reg(value);
	for (int i = 0; i < reg.size(); i++) {
		std::cout << reg[i] << std::endl;	
	}

	return EXIT_SUCCESS;
}
