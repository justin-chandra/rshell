#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

#include "Connector.h"

#ifndef And_H
#define And_H

class And: public Connector
{
	public:
		And(Rshell *, Rshell*);
		And(Rshell *);
		And(stack<char *>s);
		And();
		~And();

		Rshell * first;
		Rshell * second;
		Rshell * parent;
		string userInput;
		bool status;

		bool evaluate();
		
		Rshell * getParent();

		void setParent(Rshell *);
		void setFirst(Rshell *);
		void setSecond(Rshell *);
	private:
};

#endif
