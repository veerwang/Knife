/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  模板元编程的一个范例，有点像是数学中的递归证明
 *    		    必须注意函数是不能进行偏特化的
 *
 *        Version:  1.0
 *        Created:  2018年01月06日 20时37分52秒
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

template<typename T,int v>
class MyClass
{
public:
	static T Add()
	{
		return v + MyClass<T,v-1>::Add(); 
	}

};

template<typename T>
class MyClass<T,1>
{
public:
	static T Add()
	{
		return 1; 
	}

};
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::cout<<"meta template programe"<<std::endl;	
	std::cout<<MyClass<int,800>::Add();
	std::cout<<std::endl;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
