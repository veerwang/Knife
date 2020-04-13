/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年04月13日 
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

#include	"tsmrg.h"

int main(int argc, const char *argv[])
{
	std::cout << "ts test" << std::endl;
	tsmrg *tsm = new tsmrg();
	tsm->initilization(1024,768);

	//tsm->register_obj(100,200,10,2,1);
	tsm->register_obj(200,400,10,1,2);

	for (int i=0;i<1024;i++) {
		for (int j=0;j<768;j++) {
			if ( tsm->get_mask(i,j) )		
				std::cout << "bingo" << std::endl;
		}
	}

	tsm->release();
	delete tsm;
	return EXIT_SUCCESS;
}
