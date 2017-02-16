#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <sys/types.h>
#include <stack>
#include <queue>

using namespace std;

#include "Rshell.h"
#include "And.h"
#include "Or.h"
#include "Always.h"


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
		char * args[100];
		vector<char *> v;

		Command();
		Command(stack<char *>s);
		Command(queue<char *> q);
		Command(char * temp);
		~Command();
		bool evaluate();

		Rshell * getParent() { return NULL; }
		
		void setParent(Rshell *) {};
		void setFirst(Rshell *) {};
		void setSecond(Rshell *) {};
		

		//test stuff
	private:
};

#endif
