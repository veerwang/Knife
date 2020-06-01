/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月01日 
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
#include	"head.h"

class Base {
public:
	Base () { mId = 10; }
	Base (const Base&) { mId = 10; }
	virtual ~Base() {;}

	int getId() { return mId; }
protected:
	int mId;
	
private:
};

template<typename T = Base>
class TBase {
public:
	TBase () {;}
	TBase (const TBase&) {;}
	virtual ~TBase() {;}
protected:
	
private:
};

int 
main(int argc, const char *argv[]) {
	std::cout << "templat cprs testing" << std::endl;

	Value<Base> value;
	value.mName = "kevin";
	std::cout << value.getId() << std::endl;
	std::cout << value.mName << std::endl;

	Value<TBase<int> > tvalue;
	tvalue.mName = "WangWei";
	std::cout << tvalue.mName << std::endl;


	return EXIT_SUCCESS;
}
