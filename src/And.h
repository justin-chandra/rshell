#include <iostream>
#include <stack>
#include <string>

using namespace std;

#include "Connector.h"

#ifndef And_H
#define And_H

class And: public Connector
{
	public:
		And(Rshell *, Rshell*);
		And(stack<char *>s);
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
