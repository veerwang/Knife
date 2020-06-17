/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月16日 
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
#include	"mili/mili.h"

using namespace mili;

int main(int argc, const char *argv[])
{
	std::cout << "mili test" << std::endl;	
    	std::cout << mili::getGPL3LicenseText("mili", "16", "Fudepan Team", "2012");

	std::vector<int> v(5, 3); //all 3's
	v[1] = 1;
	v[4] = 7; //so it is [3,1,3,3,7]

	bostream<> bos;
	bos << 1 << 2 << 3 << std::string("Hello ") << v << 4 << std::string("World!");

	bostream<> bos2;
	bos2 << 100;
	bos +=  bos2;

	bistream<> bis(bos.str());

	int         nums[4];
	std::string str1;
	std::string str2;

	std::vector<int> v2;

	bis >> nums[0] >> nums[1] >> nums[2] >> str1 >> v2 >> nums[3] >> str2;

	for (int i = 0; i < 4 ; ++i)
		std::cout << nums[i] << std::endl;

	std::cout << str1 << str2 << std::endl;

	std::cout << '[';
	for (size_t i = 0; i < 5; ++i)
		std::cout << v2[i] << ' ';
	std::cout << ']' << std::endl;

	bos.clear();

	container_writer<int> cw(5, bos);

	cw << 1 << 2 << 3 << 4 << 5;

	return EXIT_SUCCESS;
}
