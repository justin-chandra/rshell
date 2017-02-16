#include <iostream>

using namespace std;

#ifndef RSHELL_H
#define RSHELL_H

class Rshell
{
	public:
	Rshell * first;
	Rshell * second;
	Rshell * parent;
	string userInput;
	bool status;

	virtual Rshell * getParent() = 0;
	virtual void setParent(Rshell *) = 0;
	virtual void setFirst(Rshell *) = 0;
	virtual void setSecond(Rshell *) = 0;

	virtual bool evaluate() = 0;
};

#endif
