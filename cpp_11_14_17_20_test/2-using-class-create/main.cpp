/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年08月25日 
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
	object () : _x(10) { _x = 20;}
	object (const object&) {;}
	virtual ~object() {;}

protected:
	int _x;
	int _y {30};

private:
};

class box : public object {
public:
	using object::object;

	void display() {
		std::cout << _x << std::endl;
	}

protected:
	
private:
};

class goodbox : public box {
public:
	using box::box;

protected:
	
private:
	
};


int 
main(int argc, const char *argv[]) {
	std::cout << "using head" << std::endl;

	box b;
	b.display();

	goodbox gb;
	gb.display();

	return EXIT_SUCCESS;
}
