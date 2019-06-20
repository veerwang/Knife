#ifndef INCLUDED_COMPONENT_H
#define INCLUDED_COMPONENT_H

class Component {
public:
	Component();
	Component(const Component&);
	virtual ~Component();

	// Leaf的接口
	virtual int GetPrice() { return 0; }
	// Composite接口
	virtual void AddComposite(Component*) {;}
	virtual void DelComposite() {;}
protected:
	
private:
	
};

#endif /* INCLUDED_COMPONENT_H */
