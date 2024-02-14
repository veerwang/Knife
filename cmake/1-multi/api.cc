/*!
    \file    api.cc
    \brief   工程实现

    \version 2024-02-14, V1.0
	\author	 kevin.wang
	\note    无
*/

#include "api.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

void disp_log(const char* msg) {
	std::cout << "Debug: " << msg << std::endl;
}
