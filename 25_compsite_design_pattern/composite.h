#ifndef INCLUDED_COMPOSITE_H
#define INCLUDED_COMPOSITE_H

#include 	"component.h"
#include 	<list>

class Composite : public Component {
public:
	Composite();
	Composite(const Composite&);
	virtual ~Composite();

	virtual void AddComposite(Component*);
	virtual void DelComposite();

	virtual int GetPrice();
protected:

	std::list<Component*>	mList;
private:
	
};

#endif /* INCLUDED_COMPOSITE_H */
