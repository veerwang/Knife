#ifndef INCLUDED_BOARDDECORATOR_H
#define INCLUDED_BOARDDECORATOR_H

#include 	"decorator.h"

class BoardDecorator : public Decorator {
public:
	BoardDecorator();
	BoardDecorator(Component* c);
	~BoardDecorator();
	
	virtual void Operation();
protected:
	
private:
	
};

#endif /* INCLUDED_BOARDDECORATOR_H */
