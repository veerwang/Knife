#ifndef INCLUDED_COMPONENT_H
#define INCLUDED_COMPONENT_H

class Component {
public:
	Component();
	virtual ~Component();
	
	// 实际输出的接口
	virtual void Operation() = 0;
protected:
	
private:
	
};

#endif /* INCLUDED_COMPONENT_H */
