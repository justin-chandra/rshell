#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

#include "Connector.h"

#ifndef OUTPUTREDIRECTO_H
#define OUTPUTREDIRECTO_H

class OutputRedirectO: public Connector
{
	public:
		OutputRedirectO(Rshell *, Rshell*);
		OutputRedirectO(Rshell *);
		OutputRedirectO(stack<char *>s);
		OutputRedirectO();
		~OutputRedirectO();

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

};

#endif
