#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <stdio.h>
#include <vector>

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
		vector<char *> v;

		bool evaluate();
		
		Rshell * getParent();
		
		void setParent(Rshell *);
		void setFirst(Rshell *);
		void setSecond(Rshell *);

};

#endif
