#include <iostream>

using namespace std;

#ifndef RSHELL_H
#define RSHELL_H

class Rshell
{
	public:
	Rshell * first;
	Rshell * second;
	string userInput;
	bool status;
	
	virtual bool evaluate() = 0;
};

#endif
