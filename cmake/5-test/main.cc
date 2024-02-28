/*!
    \file    main.cc
    \brief   主程序

    \version 2024-02-14, V1.0
	\author	 kevin.wang
	\note    无 
*/


#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "utils/module.h"
#include "api.h"

int
main(int argc, const char *argv[]) {
	std::cout << "测试程序: " << WangV::module_version() << std::endl;	
	disp_log("主程序启动");

	return EXIT_SUCCESS;
}
