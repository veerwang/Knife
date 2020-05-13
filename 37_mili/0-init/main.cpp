/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月13日 
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

#include	<mili/mili.h>

class object {
public:
	object() {;} 
	object (int id){;}
	object (const object&){;}
	virtual ~object(){;}

	virtual void drawme() = 0;
protected:
	
private:
};

class rectangle : public object {
public:
	rectangle() {;}
	rectangle (int id) { std::cout << id << std::endl;}
	rectangle (const rectangle&) {;}
	virtual ~rectangle() {;}

	void drawme() {
		std::cout << "draw rectangle" << std::endl;
	}

protected:
	
private:
};

class circle : public object {
public:
	circle() {;}
	circle (int id) { std::cout << id << std::endl; }
	circle (const circle&) {;}
	virtual ~circle() {;}

	void drawme() {
		std::cout << "draw circle" << std::endl;
	}
protected:
	
private:
	
};

int 
main(int argc, const char *argv[]) {
	std::cout << "mili test" << std::endl;

	mili::Factory<std::string, object, int> shapes_factory; 
	shapes_factory.register_factory<circle>("circle");
	shapes_factory.register_factory<rectangle>("rectangle");

	object* obj = shapes_factory.new_class("circle",10);
	obj->drawme();

	return EXIT_SUCCESS;
}
