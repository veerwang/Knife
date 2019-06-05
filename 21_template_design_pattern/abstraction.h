#ifndef INCLUDED_ABSTRACTION_H
#define INCLUDED_ABSTRACTION_H

class Abstraction {
public:
	Abstraction();
	Abstraction(const Abstraction&);
	~Abstraction();
	
	virtual void TemplateMethod ();
	virtual void Process();
protected:
	virtual void Hook1();	
private:
	
};


#endif /* INCLUDED_ABSTRACTION_H */
