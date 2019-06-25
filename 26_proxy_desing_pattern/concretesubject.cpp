#include 	"concretesubject.h"
#include 	<iostream>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ConcreteSubject
 *  Description:  默认构造函数 
 * =====================================================================================
 */
ConcreteSubject::ConcreteSubject () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~ConcreteSubject
 *  Description:  默认析构函数 
 * =====================================================================================
 */
ConcreteSubject::~ConcreteSubject () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ConcreteSubject  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
ConcreteSubject::ConcreteSubject(const ConcreteSubject& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  Request 
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
void ConcreteSubject::Request() {
	std::cout << "Core Request Function" << std::endl;
}
