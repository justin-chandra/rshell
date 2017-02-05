#include <iostream>

using namespace std;

#include "Connector.h"

#ifndef Or_H
#define Or_H

class Or: public Connector
{
	public:
		Rshell * first;
		Rshell * second;
		string userInput;
		bool status;

		Or();
		~Or();
		bool evaluate();
	private:
};

#endif
