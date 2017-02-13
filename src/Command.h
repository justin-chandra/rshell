#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <sys/types.h>
#include <stack>

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
		string userInput;
		bool status;
		stack<char *> commands;
		stack<char *> temp;
		char * command;
		char * args[100];

		Command();
		Command(stack<char*>s);
		Command(char * temp);
		~Command();
		bool evaluate();

		//test stuff
	private:
};

#endif
