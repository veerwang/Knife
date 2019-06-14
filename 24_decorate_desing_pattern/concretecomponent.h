#ifndef INCLUDED_CONCRETECOMPONENT_H
#define INCLUDED_CONCRETECOMPONENT_H

#include 	"component.h"

class ConcreteComponent : public Component {
public:
	ConcreteComponent();
	virtual ~ConcreteComponent();

	virtual void Operation();
protected:
	
private:
	
};


#endif /* INCLUDED_CONCRETECOMPONENT_H */
