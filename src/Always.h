#include <iostream>

using namespace std;

#include "Connector.h"
#include <stack>
#include <string>


#ifndef Always_H
#define Always_H

class Always: public Connector
{
	public:
		Rshell * first;
		Rshell * second;
		string userInput;
		bool status;
		
		Always();
		Always(stack<char *> s);
		~Always();
		bool evaluate();
	private:
};

#endif
