/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年09月01日 
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

class Object {
public:
	Object () {;}
	Object (const Object&) {;}
	virtual ~Object() {;}

	void disp_id() {
		std::cout << _id << std::endl;
	}
protected:
	int _id {99};
	
private:
	
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  display_version
 *  Description:  显示本程序版本信息函数 
 * =====================================================================================
 */
void display_version() {
	std::cout << "ccls test" << std::endl;	
}

int 
main(int argc, const char *argv[]) {
	display_version();
	Object obj;
	obj.disp_id();
	return EXIT_SUCCESS;
}
