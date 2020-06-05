#ifndef INCLUDED_HEAD_H
#define INCLUDED_HEAD_H

#include <string>
#include <iostream>

template<typename T>
class Value : public T {
public:
	Value () {;}
	Value (const Value&) {;}
	virtual ~Value() {;}

	std::string mName;
protected:
	
private:
	
};

/* object class define */
class object {
public:
	object () { std::cout << "object create" << std::endl;}
	object (const object&) {;}
	virtual ~object() { std::cout << "object destroy" << std::endl; }

protected:
	
private:
};

template <typename T>
class tobject {
public:
	tobject () { std::cout << "tobject create" << std::endl; }
	tobject (const tobject&);
	virtual ~tobject() { std::cout << "tobject destroy" << std::endl; }

protected:
	
private:
	
};

template<>
tobject<int>::tobject() {
	std::cout << "int tobject create" << std::endl;
}

/* C++11 这种写法才支持 */
template <typename T = tobject<int>>
class human : public T {
public:
	human () { std::cout << "human create" << std::endl;;}
	human (const human&) { ;}
	virtual ~human() { std::cout << "human destroy" << std::endl;}

protected:
	
private:
	
};


#endif /* INCLUDED_HEAD_H */
