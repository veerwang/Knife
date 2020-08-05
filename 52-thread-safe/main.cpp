/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月05日 
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
	object () {;}
	object (const object&) {;}
	virtual ~object() {;}

protected:
	
private:
	
};



int 
main(int argc, const char *argv[]) {
	std::cout << "thread safe pro V1.0.0" << std::endl;	
	return EXIT_SUCCESS;
}
