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
void testDefaultValue(Object v) {
	v.Disp();
}

// 该种传递方式比上面一种要强
// 不会发生拷贝复制过程
void testNormalValue(Object &v) {
	v.Disp();
}

//
void testRightValue(Object &&v) {
	v.Disp();
}

int
main(int argc, const char *argv[]) {
	Object obj;
	//testDefaultValue(obj);	
	//testNormalValue(Object());
	//testRightValue(Object());
	
	// 重要代码，这样的调用，只产生一次的构造过程
	// 没有调用复制构造函数
	testRightValue(std::move(obj));
	return EXIT_SUCCESS;
}
