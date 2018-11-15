/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: for_each 
 *
 *        Version:  1.0
 *        Created:  2018年11月23日 13时44分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

void function(int i)
{
	std::cout<<"index: "<<i<<std::endl;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::vector<int> vgroup;
	vgroup.push_back(10);
	vgroup.push_back(20);
	vgroup.push_back(30);
	vgroup.push_back(40);

	for_each(vgroup.begin(),vgroup.end(),function);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
