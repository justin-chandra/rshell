#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <sys/types.h>
#include <stack>
#include <queue>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

#include "Rshell.h"
#include "And.h"
#include "Or.h"
#include "Always.h"
#include "Test.h"


#ifndef Command_H
#define Command_H

class Command: public Rshell
{
	public:
		Rshell * first;
		Rshell * second;
		Rshell * parent;
		string userInput;
		bool status;
		stack<char *> commands;
		stack<char *> temp;
		char * command;
		vector<char *> v;
		char * args[100];

		Command();
		Command(stack<char *>s);
		~Command();
		bool evaluate();

		Rshell * getParent() { return NULL; }
		
		void setParent(Rshell *) {};
		void setFirst(Rshell *) {};
		void setSecond(Rshell *) {};
		vector<char *> getVector();

	private:
};

#endif
