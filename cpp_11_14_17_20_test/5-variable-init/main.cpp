/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月28日 
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
	/* 此处的初始化滞后于{}初始化，因此最终的数值是20 */
	object () : id(20) {;}
	object (const object&) {;}
	virtual ~object() {;}

	void display() {
		std::cout << "id = " << id << std::endl;
		std::cout << "name = " << name << std::endl;
	}

	const std::string name = {"kevin"};
protected:
	
private:
	/* 初始化 */
	int id = {10};
};



int main(int argc, const char *argv[]) {
	std::cout << "variables init" << std::endl;	
	object obj;
	obj.display();

	return EXIT_SUCCESS;
}
