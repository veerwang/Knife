#ifndef INCLUDED_CONCRETESUBJECT_H
#define INCLUDED_CONCRETESUBJECT_H

class ConcreteSubject {
public:
	ConcreteSubject();
	ConcreteSubject(const ConcreteSubject&);
	virtual ~ConcreteSubject();

	virtual void Request();	
protected:
	
private:
	
};

#endif /* INCLUDED_CONCRETESUBJECT_H */
