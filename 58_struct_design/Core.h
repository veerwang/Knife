#ifndef INCLUDED_CORE_H
#define INCLUDED_CORE_H

#include <iostream>

class None {
public:
	None () {;}
	None (const None&) {;}
	virtual ~None() {;}

};

class Core : public None {
public:
	using None::None;

	virtual void DoProcess() {;}
};

class Msgbox : public None {
public:
	using None::None;

	virtual void DoProcess() { std::cout << "msgbox" << std::endl;;}
protected:
	
private:
	
};

class Frame : public None {
public:
	using None::None;

	virtual void DoProcess() { std::cout << "Frame" << std::endl;;}
protected:
	
private:
	
};

#endif /* INCLUDED_CORE_H */
