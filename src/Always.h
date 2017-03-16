#include <iostream>

using namespace std;

#include "Connector.h"
#include <stack>
#include <string>


#ifndef Always_H
#define Always_H

//looks similar to And.h and Or.h

class Always: public Connector
{
	public:
		Rshell * first;
		Rshell * second;
		Rshell * parent;
		string userInput;
		bool status;
		
		Always();
		Always(stack<char *> s);
		~Always();
		bool evaluate();
		bool evaluate(int in, int out);

		Rshell * getParent();

		void setParent(Rshell *);
		void setFirst(Rshell *);
		void setSecond(Rshell *);

	private:
};

#endif
