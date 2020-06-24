/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月24日 
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

class object {
public:
	object () : id(100) {;}
	object (const object&) {;}
	virtual ~object() {;}

protected:
	int id;	
	
private:
};

class circle : public object {
public:
	/* 使用基类的初始化函数 */
	using object::object;

	void display() { std::cout << id << std::endl;;}
protected:
	
private:
	
};

int main(int argc, const char *argv[]) {
	std::cout << "class create V1.0.0" << std::endl;
	circle c;
	c.display();
	return EXIT_SUCCESS;
}
