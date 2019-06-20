#ifndef INCLUDED_LEAF_H
#define INCLUDED_LEAF_H

#include 	"component.h"

class Leaf : public Component {
public:
	Leaf();
	Leaf(const Leaf&);
	virtual ~Leaf();
	virtual int GetPrice();	
protected:
	
private:
	int _mPrice;	
};

#endif /* INCLUDED_LEAF_H */
