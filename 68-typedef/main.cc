/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  类的描述
 *
 *        Version:  1.0
 *        Created:  2021年10月09日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

class Base {
  public:
	Base () {;}
	Base (const Base&) {;}
	virtual ~Base() {;}

	typedef uint32_t CTYPE;

	CTYPE Display();
  protected:
	
  private:
	
};

CTYPE Base::Display() {
	return 100;
}

int 
main(int argc, const char *argv[]) {
	Base base;
	Base::CTYPE a;
	a = 1000;
	std::cout << a << std::endl;
	std::cout << base.Display() << std::endl;
	return EXIT_SUCCESS;
}
