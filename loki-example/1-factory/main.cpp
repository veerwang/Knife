/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月12日 
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
#include 	<string.h>

#include 	<loki/Factory.h>

/* 基类 */
class gobject {
public:
	gobject () {;}
	gobject (const gobject&) {;}
	virtual ~gobject() {;}

	virtual void drawme() = 0;

protected:
private:
};

class label : public gobject {
public:
	label () {;}
	label (const label&) {;}
	virtual ~label() {;}

	virtual void drawme() {
		std::cout << "label display" << std::endl;
	} 
protected:
	
private:
	
};

class button : public gobject {
public:
	button () {;}
	button (const button&) {;}
	virtual ~button() {;}

	virtual void drawme() {
		std::cout << "button display" << std::endl;
	} 
protected:
	
private:
	
};

/* 创建屏幕类的函数,用于注册使用 */
gobject* create_label(int id) {
	std::cout << "id: " << id << std::endl;
	gobject *obj = new label();
	return obj;
}

gobject* create_button(int id) {
	std::cout << "id: " << id << std::endl;
	gobject *obj = new button();
	return obj;
}

/* 声明工厂类 */
typedef Loki::Factory<gobject,std::string,LOKI_TYPELIST_1( int )> GFACTORY;

int 
main(int argc, const char *argv[]) {
	std::cout << "loki factory test" << std::endl;	

	GFACTORY gfactory;

	/* 注册 */
	gfactory.Register("label",create_label);
	gfactory.Register("button",create_button);

	/* 创建 */
	gobject *obj1 = gfactory.CreateObject("label",1);
	gobject *obj2 = gfactory.CreateObject("button",2);

	/* 使用 */
	obj1->drawme();
	obj2->drawme();

	delete obj1;
	delete obj2;

	return EXIT_SUCCESS;
}
