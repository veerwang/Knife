#include 	"abstraction.h"

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Abstraction
 *  Description:  默认构造函数 
 * =====================================================================================
 */
Abstraction::Abstraction () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~Abstraction
 *  Description:  默认析构函数 
 * =====================================================================================
 */
Abstraction::~Abstraction () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Abstraction  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
Abstraction::Abstraction(const Abstraction& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  TemplateMethod
 *  Description:  模板函数 
 * =====================================================================================
 */
void Abstraction::TemplateMethod () {
	std::cout << "Abstraction TemplateMethod" << std::endl;
	return;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DoMethod1 
 *  Description:  处理函数 
 * =====================================================================================
 */
void Abstraction::Hook1() {
	std::cout << "Abstraction Hook1" << std::endl;
	return;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Process 
 *  Description:  整体处理函数 
 * =====================================================================================
 */
void Abstraction::Process () {
	Hook1();
	return;
}
