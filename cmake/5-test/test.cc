/*!
    \file    main.cc
    \brief   测试程序

    \version 2024-02-14, V1.0
	\author	 kevin.wang
	\note    无 
*/

#include "utils/module.h"
#include "api.h"
#include <cstdlib>

int
main(int argc, const char *argv[]) {
	int intvalue = 0;
	std::string numstr = "16";
	intvalue = WangV::string_to_number(numstr);

	if (intvalue != 16) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
