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

// 重要语句，这里的声明很重要
// T&& 推导原则： 左值实参依旧是左值实参数，右值实参依旧是右值实参数
// 一套模板就可以适配左右实参数
template<typename T>
void forword_process(T&& value)
{
	std::cout << value << std::endl;
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

	// 对于常量与普通引用变量需要两种模板
	/*
	template<typename T>
	void forword_process(T& value)
	{
		std::cout << value << std::endl;
	}
	template<typename T>
	void forword_process(const T& value)
	{
		std::cout << value << std::endl;
	}
	*/
	// 如果是右引用就是只要一种就行了
	const int& a = 10;
	forword_process(a);
	forword_process(20);

	return EXIT_SUCCESS;
}
