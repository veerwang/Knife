/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月28日 
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

class object {
public:
	object () {;}
	object (const object&) {;}
	virtual ~object() {;}

	virtual void display() final {
		std::cout << "object display" << std::endl;
	}

	virtual void trigger() {
		std::cout << "trigger in object" << std::endl;
	}
protected:
	
private:
	
};

class circle : public object {
public:
	circle () {;}
	circle (const circle&) {;}
	virtual ~circle() {;}

	/* 注意基类中的对应函数必须存在，否则不能用override进行限定 */
	virtual void trigger() override {
		std::cout << "trigger in circle" << std::endl;
	}

	/* 由于基类的final属性的存在，因此不能进行虚函数的改写 */
	/*
	virtual void display() {
		std::cout << "circle display" << std::endl;
	}
	*/
protected:
	
private:
	
};

int main(int argc, const char *argv[]) {
	std::cout << "template v1.0.0"  << std::endl;	

	circle c;
	c.display();
	c.trigger();

	return EXIT_SUCCESS;
}
