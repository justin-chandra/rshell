#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

#include "Connector.h"
#ifndef PIPE_H
#define PIPE_H

class Pipe: public Connector
{
	public:
		Pipe(Rshell *, Rshell*);
		Pipe(Rshell *);
		Pipe(stack<char *>);
		Pipe();
		~Pipe();

		Rshell * first;
		Rsheel * second;
		Rshell * parent;
		string userInput;
		bool status;

		bool evaluate();
		
		Rshell * getParent();
		
		void setParent(Rshell *);
		void setFirst (Rshell *);
		void setSecond(Rshell *);
};

#endif
