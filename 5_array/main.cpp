/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年03月23日 13时44分09秒
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

#include <array>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::cout<<"array test v1.0.0"<<std::endl;
	std::array<int,5> a = { 1,2,3,4,5 };

	/*
	 * access each element of array
	 */
	std::cout<<"a[0] = "<<a[0]<<std::endl;

	/*
	 * property access 
	 */
	std::cout<<"size = "<<a.size()<<std::endl;
	std::cout<<"maxsize = "<<a.max_size()<<std::endl;
	std::cout<<"sizeof(a) = "<<sizeof(a)<<std::endl;


	for ( auto i=a.begin();i!=a.end();++i )
		std::cout<<"a[]"<<*i<<std::endl;

	/*
	 *  init array method
	 */
	a.fill(0);

	/*
	 * loop each element 
	 */
	for ( auto i=a.begin();i!=a.end();i++ )
		std::cout<<"a[]"<<*i<<std::endl;


	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
