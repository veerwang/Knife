#include 	"implementation.h"

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Implementation
 *  Description:  默认构造函数 
 * =====================================================================================
 */
Implementation::Implementation () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~Implementation
 *  Description:  默认析构函数 
 * =====================================================================================
 */
Implementation::~Implementation () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Implementation  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
Implementation::Implementation(const Implementation& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  TemplateMethod
 *  Description:  模板函数，子类改写父类的行为
 * =====================================================================================
 */
void Implementation::TemplateMethod () {
	std::cout << "Implementation TemplateMethod" << std::endl;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Hook 
 *  Description:  钩子函数,调用由父类进行
 * =====================================================================================
 */
void Implementation::Hook1() {
	std::cout << "Implementation Hook1" << std::endl;
}
