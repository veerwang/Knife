#ifndef INCLUDED_SUBJECT_H
#define INCLUDED_SUBJECT_H

class Subject {
public:
	Subject();
	Subject(const Subject&);
	virtual ~Subject();

	virtual void Request() = 0;
protected:
	
private:
	
};

#endif /* INCLUDED_SUBJECT_H */
