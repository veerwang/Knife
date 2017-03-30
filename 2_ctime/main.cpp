/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年03月30日 14时40分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::cout<<"ctime programe test V1.0.0"<<std::endl;
	/*
	 * 时间流逝
	 */
	clock_t t = clock();
	for ( int i=0;i<800000;i++ )
		printf("clock ..\n");
	t = clock() - t;
	std::cout<<"it take me clock: %d "<<t<<std::endl;
	float time = static_cast<float>(t) / CLOCKS_PER_SEC;
	std::cout<<"it take me seconds: %d "<<time<<std::endl;







	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
