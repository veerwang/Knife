#ifndef INCLUDED_STATUS_H
#define INCLUDED_STATUS_H

class Status {
public:
	Status();
	Status(const Status&);
	~Status();

	virtual void Handle();	
protected:
	
private:
	
};

#endif /* INCLUDED_STATUS_H */
