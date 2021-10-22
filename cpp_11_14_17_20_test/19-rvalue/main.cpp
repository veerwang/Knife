/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  进行右数值传递的实验
 *
 *        Version:  1.0
 *        Created:  2021年10月22日 
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

class Object {
  public:
	Object () { std::cout << "Create[0] Object" << std::endl;}
	Object (const Object&) { std::cout << "Create[1] Object" << std::endl;}
	virtual ~Object() { std::cout << "Destroy Object" << std::endl; }

	void Disp() { std::cout << "Display" << std::endl; }
  protected:
	
  private:
	
};

// 重点测试，这种传递方式产生拷贝构造函数 
// 效率很低 
void testRValue(Object v) {
	v.Disp();
}

int 
main(int argc, const char *argv[]) {
	Object obj;
	testRValue(obj);	
	return EXIT_SUCCESS;
}
