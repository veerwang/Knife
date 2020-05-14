/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月14日 
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
#include 	<functional>

int 
add(int x1,int x2) {
	return x1 + x2;
}

class object {
public:
	object () {;}
	object (const object&){;}
	virtual ~object(){;}

	int add(int x1,int x2) { return 2 * x1 + x2; }
protected:
	
private:
	
};

int main(int argc, const char *argv[])
{
	/* auto -std=c++11  */
	auto fun = std::bind(add,std::placeholders::_1,std::placeholders::_2);
	std::cout << "bind test" << std::endl;
	std::cout << "result-1:= " << fun(10,20) << std::endl;

	object obj;
	typedef std::function<int (int,int)> Interface;
	Interface classfun = std::bind(&object::add,&obj,std::placeholders::_1,std::placeholders::_2);
	std::cout << "result-2:= " << classfun(10,20) << std::endl;

	return EXIT_SUCCESS;
}
