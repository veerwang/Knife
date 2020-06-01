#ifndef INCLUDED_HEAD_H
#define INCLUDED_HEAD_H

#include <string>


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

#endif /* INCLUDED_HEAD_H */
