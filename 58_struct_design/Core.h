#ifndef INCLUDED_CORE_H
#define INCLUDED_CORE_H

#include <iostream>

class Core {
public:
	Core() {;}
	Core (const Core& c) {;}
	virtual ~Core() {;}

	virtual void DoProcess() {;}
};

class Msgbox {
public:
	Msgbox () {;}
	Msgbox (const Msgbox&) {;}
	virtual ~Msgbox() {;}

	virtual void DoProcess() { std::cout << "msgbox" << std::endl;;}
protected:
	
private:
	
};

#endif /* INCLUDED_CORE_H */
