#ifndef INCLUDED_DECORATOR_H
#define INCLUDED_DECORATOR_H

#include 	"component.h"

class Decorator : public Component {
public:
	Decorator();
	Decorator(Component* c);
	~Decorator();
	
	virtual void Operation();
protected:

	Component* _mComponent;
private:
};

#endif /* INCLUDED_DECORATOR_H */
