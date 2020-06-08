/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月08日 
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
#include	<string>

class base {
public:
	base () { std::cout << "base default create" << std::endl; }
	base (const base&) { std::cout << "base = create" << std::endl; }
	base (std::string name) { std::cout << "base name " << name << std::endl;}
	virtual ~base() {;}

protected:
	
private:
	
};

class circle : public base {
public:
	circle () {;}
	circle (const circle&) {;}
	circle (std::string name) 
		: base(name)			// 如果不直接调用该函数，那么他默认会调用默认构造函数
	{	
		std::cout << "name" << name << std::endl;
	}
	virtual ~circle() {;}

protected:
	
private:
	
};

int main(int argc, const char *argv[])
{
	std::cout << "Base Class Test" << std::endl;	
	circle cc("kevin");

	return EXIT_SUCCESS;
}
