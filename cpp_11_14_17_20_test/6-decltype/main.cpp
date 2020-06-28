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

	virtual void display() {
		std::cout << "object" << std::endl;
	}
protected:
	
private:
};

class rect : public object {
public:
	rect () {;}
	rect (const rect&) {;}
	virtual ~rect() {;}

	virtual void display() {
		std::cout << "rect" << std::endl;
	}
protected:
	
private:
	
};

class circle : public object {
public:
	circle () {;}
	circle (const circle&) {;}
	virtual ~circle() {;}

	virtual void display() {
		std::cout << "circle" << std::endl;
	}
protected:
	
private:
	
};

int main(int argc, const char *argv[]) {
	std::cout << "delctype test" << std::endl;	
	int i = 10;
	decltype(i) b = 50;
	std::cout << b << std::endl;
	
	circle c;
	decltype(c) obj;
	obj.display();

	object *o = &c;
	o->display();

	/* 根据具体的变量来判断类型 */
	decltype(o) p = o; 
	p->display();

	return EXIT_SUCCESS;
}
