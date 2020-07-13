/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月24日 
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
	object () : id(100) {;}
	object (const object&) {;}
	object (int x,int y,int w,int h) {
		_x = x;
		_y = y;
		_w = w;
		_h = h;
	}
	virtual ~object() {;}

protected:
	int id;	
	int _x;
	int _y;
	int _w;
	int _h;
private:
};

class circle : public object {
public:
	/* 使用基类的初始化函数 */
	using object::object;

	void display() { std::cout << id << std::endl;}
	void showme() {
		std::cout << _x << std::endl;
		std::cout << _y << std::endl;
	}
protected:
	
private:
	
};

int main(int argc, const char *argv[]) {
	std::cout << "class create V1.0.0" << std::endl;
	circle c;
	c.display();

	circle nc(1,2,3,4);
	nc.showme();

	return EXIT_SUCCESS;
}
