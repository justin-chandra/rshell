#include <iostream>
#include <stack>
#include <vector>

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
		vector<char *> args;

		Command();
		Command(string s);
		Command(char * argument);
		~Command();
		void build(string input);
		bool evaluate();

		//test stuff
		void stack_print(stack<char*>s);
	private:
};

#endif
