#ifndef INCLUDED_IMPLEMENTATION_H
#define INCLUDED_IMPLEMENTATION_H

#include 	"abstraction.h"

class Implementation : public Abstraction 
{
public:
	Implementation();
	Implementation(const Implementation&);
	~Implementation();

	virtual void TemplateMethod();

protected:
	
private:
	
};

#endif /* INCLUDED_IMPLEMENTATION_H */
