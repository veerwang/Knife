#ifndef INCLUDED_CONCRETSUBJECT_H
#define INCLUDED_CONCRETSUBJECT_H

#include 	"subject.h"

class ConcretSubject : public Subject {
public:
	ConcretSubject();
	ConcretSubject(const ConcretSubject&);
	~ConcretSubject();

	inline void setID(int value) { mID = value; }
	inline int  getID() { return mID; }
protected:
	
private:
	int 	mID;
};

#endif /* INCLUDED_CONCRETSUBJECT_H */
