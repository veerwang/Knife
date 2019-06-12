#ifndef INCLUDED_SUBJECT_H
#define INCLUDED_SUBJECT_H

#include 	<list>

#include 	"observer.h"

class Subject {
public:
	Subject();
	Subject(const Subject&);
	~Subject();

	void Attach(Observer &);
	void Detach(Observer &);

	virtual void Notify();

protected:
	
private:
	std::list<Observer> mlist;	
};

#endif /* INCLUDED_SUBJECT_H */
