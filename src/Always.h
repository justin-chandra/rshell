#include <iostream>

using namespace std;

#include "Connector.h"

#ifndef Always_H
#define Always_H

class Always: public Connector
{
	public:
		Rshell * first;
		Rshell * second;
		string userInput;
		bool status;
		
		Always();
		~Always();
		bool evaluate();
	private:
};

#endif
