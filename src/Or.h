#include <iostream>

using namespace std;

#include <stack>
#include <string>
#include "Connector.h"

#ifndef Or_H
#define Or_H

class Or: public Connector
{
	public:
		Rshell * first;
		Rshell * second;
		Rshell * parent;
		string userInput;
		bool status;

		Or();
		~Or();
		Or(stack<char *>s);
		Or(Rshell *f, Rshell *s);
		bool evaluate();

		Rshell * getParent();

		void setParent(Rshell *);
		void setFirst(Rshell *);
		void setSecond(Rshell *);

	private:
};

#endif
