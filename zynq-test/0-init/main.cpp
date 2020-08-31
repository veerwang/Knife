/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月31日 
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

#define VALUE 0x7E480CC4

void 
parsing_firmware_time_info(u_int32_t info) {
	int minuts = info & 0x3F;
	std::cout << "minuts: " << minuts << std::endl;

	int hours = (info >> 6) & 0x1F;
	std::cout << "hours: " << hours << std::endl;

	int day = (info >> 11) & 0x1F;
	std::cout << "day: " << day << std::endl;

	int month = (info >> 16) & 0x0F;
	std::cout << "month: " << month << std::endl;

	int year = (info >> 20);
	std::cout << "year: " << year << std::endl;

	std::cout << "times: " << year << "-" << month << "-" << day << " " << hours << ":" << minuts << std::endl;
}

int 
main(int argc, const char *argv[]) {
	std::cout << "zynq test V1.0.0" << std::endl;	

	parsing_firmware_time_info(VALUE);

	return EXIT_SUCCESS;
}
