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
#include 	<vector>
#include 	<set>

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

struct S {};

int 
main(int argc, const char *argv[]) {
	std::cout << "mili test" << std::endl;

	mili::Factory<std::string, object, int> shapes_factory; 
	shapes_factory.register_factory<circle>("circle");
	shapes_factory.register_factory<rectangle>("rectangle");

	object* obj = shapes_factory.new_class("circle",10);
	obj->drawme();

	std::cout << bool(mili::template_info<S>::is_native) << std::endl;
	std::cout << bool(mili::template_info<char>::is_native) << std::endl;
	std::cout << bool(mili::template_info<int>::is_same_size<long int>::value) << std::endl;
	std::cout << bool(mili::template_info<std::vector<int> >::is_container) << std::endl;
	std::cout << bool(mili::template_info<std::set<int> >::is_container) << std::endl;

	return EXIT_SUCCESS;
}
