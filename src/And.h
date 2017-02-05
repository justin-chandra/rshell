#include <iostream>

using namespace std;

#include "Connector.h"

#ifndef And_H
#define And_H

class And: public Connector
{
	public:
		And();
		~And();
		Rshell * first;
		Rshell * second;
		string userInput;
		bool status;


		bool evaluate();
	private:
};

#endif
