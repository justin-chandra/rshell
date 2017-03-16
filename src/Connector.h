#include <iostream>

using namespace std;

#include "Rshell.h"

#ifndef Connector_H
#define Connector_H

class Connector: public Rshell
{
	public:
	Connector();
	~Connector();
	Rshell * first;
	Rshell * second;
	Rshell * parent;
	string userInput;
	bool status;

	
	virtual bool evaluate();
	virtual bool evaluate(int in, int out);
	virtual Rshell * getParent();
	virtual void setParent(Rshell *);
	virtual void setFirst(Rshell *);
	virtual void setSecond(Rshell *);
	
	
	private:
};

#endif
