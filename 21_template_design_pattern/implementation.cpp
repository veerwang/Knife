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
 *  Description:  模板程序 
 * =====================================================================================
 */
void Implementation::TemplateMethod () {
	std::cout << "Implementation TemplateMethod" << std::endl;
}
