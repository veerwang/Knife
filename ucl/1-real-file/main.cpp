/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

#include <ucl/ucl.h>

#include "uclmrg.h"
#include "fileopt.h"

int 
main(int argc, const char *argv[]) {
	std::cout << "ucl test" << std::endl;

	uclmrg uclm;
	if ( uclm.init() ) {
		std::cout << "uclmrg init sccessful" << std::endl;
	}

	std::vector<char> context;
	ZFile zf;
	zf.Read("README.md",context);
	char *buf = new char[context.size()];
	int l = context.size();
	for ( int i=0;i<l;i++ ) {
		buf[i] = context[i];
	}
	uclm.config((u_int8_t *)buf,l);
	uclm.compress();

	u_int8_t* out = uclm.outbuf;
	u_int32_t ol  = uclm.out_length;
	zf.Write("README.md.ucl",(const void *)out,ol);




	delete[] buf;
	buf = nullptr;
	uclm.release();

	return EXIT_SUCCESS;
}
