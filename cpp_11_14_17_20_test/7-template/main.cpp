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

class basepolicy {
public:
	basepolicy () {;}
	basepolicy (const basepolicy&) {;}
	virtual ~basepolicy() {;}

protected:
	
private:
	
};

template<typename T>
class intpolicy {
public:
	intpolicy () {;}
	intpolicy (const intpolicy&) {;}
	virtual ~intpolicy() {;}

protected:
	
private:
	
};

template<typename T = basepolicy>
class handle : public T {
public:
	handle () {;}
	handle (const handle&) {;}
	virtual ~handle() {;}

protected:
	
private:
	
};

int main(int argc, const char *argv[]) {
	std::cout << "template v1.0.0"  << std::endl;	

	handle<> m;
	
	/* 注意这边>>是可以支持的 */
	handle<intpolicy<int>> h;

	return EXIT_SUCCESS;
}
