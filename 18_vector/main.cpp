/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  vector的相关操作 
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
#include <vector>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::vector<int> ngroup;
	for (int i=0;i<10;i++)
		ngroup.push_back(i);

	for (std::vector<int>::iterator it=ngroup.begin();it!=ngroup.end();it++)
		std::cout<<" value="<<*it<<std::endl;

	std::cout<<" ======="<<std::endl;

	std::cout<<" front="<<ngroup.front()<<std::endl;
	std::cout<<" back="<<ngroup.back()<<std::endl;

	std::cout<<" ======="<<std::endl;

	for (std::vector<int>::reverse_iterator it=ngroup.rbegin();it!=ngroup.rend();it++) //　好蠢笨啊，谁还会去用另外一个iterator晕倒.
		std::cout<<" value="<<*it<<std::endl;

	std::cout<<" size= "<<ngroup.size()<<std::endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
