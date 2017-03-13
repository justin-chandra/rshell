#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

#include "Connector.h"

#ifndef OUTPUTREDIRECTA_H
#define OUTPUTREDIRECTA_H

class OutputRedirectA: public Connector
{
	public:
		OutputRedirectA(Rshell *, Rshell*);
		OutputRedirectA(Rshell *);
		OutputRedirectA(stack<char *>s);
		OutputRedirectA();
		~OutputRedirectA();

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
