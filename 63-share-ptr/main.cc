/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  智能指针
 *
 *        Version:  1.0
 *        Created:  2020年10月22日 
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
#include 	<cstring>
#include 	<memory>

class Object {
  public:
	Object () { std::cout << "Init Object" << std::endl; }
	Object (std::string name) { Name_ = name; std::cout << Name_ << " Init Object" << std::endl; }
	Object (const Object&) { ; }
	virtual ~Object() { std::cout << Name_ << " Destroy Object" << std::endl; }

	void Display() {
		std::cout << Name_ << " Display Object" << std::endl;
	}

  protected:
	
  private:
	std::string Name_;
};

int 
main(int argc, const char *argv[]) {
	std::cout << "shared_ptr" << std::endl;	

	// 最基本的使用shared_ptr的方法
	std::shared_ptr<Object> kevinhandle(new Object("kevin"));
	kevinhandle->Display();

	// 第二种初始化的方法
	std::shared_ptr<Object> veerhandle = std::make_shared<Object>("veer");
	veerhandle->Display();

	// 必须要说明一点，shared_ptr只会调用delete，去释放资源
	// 如果申请的是数组，需要调用delete[] 进行释放
	// C++11 的使用方法
	std::shared_ptr<int> wanghandle(new int[10](),std::default_delete<int[]>());
	for (int i = 0; i < 10; i++) {
		wanghandle.get()[i] = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << wanghandle.get()[i] << std::endl;
	}

	return EXIT_SUCCESS;
}
