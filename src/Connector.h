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
	string userInput;
	bool status;

	virtual bool evaluate();
	
	private:
};

#endif
