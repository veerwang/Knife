/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  在try中进行资源的泄露的预防
 *
 *        Version:  1.0
 *        Created:  2020年10月13日 
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
#include	<exception>

struct ZeroException : public std::exception {
	virtual const char* what() noexcept {
		return "Zero Exception";
	}
};

class Object {
  public:
	Object () {;}
	Object (const Object&) {;}
	virtual ~Object() { std::cout << "internalflag_: " << internalflag_ << std::endl;;}

	void Enable() {
		internalflag_ = true;
	}
	void Disable() {
		internalflag_ = false;
	}

	void Process1() {
		Enable();
		int div = 0;
		if ( div == 0 )
			// 由于此处的throw语句，导致下面的Disable将不能够被执行
			throw ZeroException();
		std::cout << div << std::endl;
		Disable();
	}

	class ObjectHandle {
	  public:
		ObjectHandle (Object* obj) { obj_ = obj; obj_->Enable(); }
		virtual ~ObjectHandle() { obj_->Disable(); }

	  protected:

	  private:
		Object* obj_;

	};

	void Process2() {
		// 注意此处的技巧，利用C++类对象的生命周期，进行释放资源的操作，尽管发生了异常，也一样会释放
		ObjectHandle(this);
		int div = 0;
		if ( div == 0 )
			throw ZeroException();
		std::cout << div << std::endl;
	}

  protected:
	
  private:
	bool internalflag_ { true };
};

void f(Object &obj) {
	try {
		//obj.Process1();
		obj.Process2();
	} catch ( ZeroException &e ) {
		std::cerr << e.what() << std::endl;	
	}
}

int 
main(int argc, const char *argv[]) {
	std::cout << "resource leak" << std::endl;
	Object obj;
	f(obj);
	return EXIT_SUCCESS;
}
