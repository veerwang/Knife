/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月11日 
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
#include 	<string>
#include	<algorithm>

template <typename T>
std::string toString(T x) {
    std::string s;
    while (x) {
        s.push_back(x % 10 + '0');
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

long long toInt(std::string &x) {
    long long sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum *= 10;
        sum += (x[i]-'0');
    }
    return sum;
}

int 
main(int argc, const char *argv[]) {
	std::cout << "Test Programe V1.0.0" << std::endl;	
	std::string s = "1010101";
	std::cout << toInt(s) << std::endl;
	std::cout << toString(0x0a) << std::endl;

	return EXIT_SUCCESS;
}
