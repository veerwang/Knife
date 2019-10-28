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
#include <memory>

class Base {
public:
	Base() { std::cout << "Base Create" << std::endl; };
	Base(const Base&);
	virtual ~Base() { std::cout << "Base Destroy" << std::endl; };
	
	void Display() { std::cout << "Base Display" << std::endl; };
protected:
	
private:
	
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
	// 自动指针，会自行进行析构
	std::unique_ptr<Base> ppoint( new Base() );
	ppoint->Display();
	return EXIT_SUCCESS;
}
