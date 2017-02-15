#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <vector>
#include <stack>

using namespace std;

#include "Rshell.h"
#include "Connector.h"

#include "And.h"
#include "Or.h"
#include "Always.h"
#include "Command.h"

stack<Rshell *> build(stack<char *> & in);
void stack_print(stack<char *> s);
char * combine(stack<char *> s);
Rshell * root(stack<Rshell *> & s);

int main(int argc, char * argv[])
{	
	stack<char *> in;	

	//gets username
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);	


	string input;
	while (1 == 1)
	{
		stack<Rshell *> connectors;
		cout << username << "@" << hostname << "$ ";
		getline(cin, input);

		//converts to cstring
		char * cstring = new char[input.size() + 1];
		strcpy(cstring, input.c_str());

		char * parsed = strtok(cstring, " ");
		//exit needs to be somewhere else where it can be caught
		//during execution
		string exit = "exit";
		if (parsed != NULL)
		{
			if (parsed == exit)
			{
				return 0;
			}
			in.push(parsed);
		}
		while (parsed != NULL)
		{
			parsed = strtok(NULL, " ");
			if (parsed != NULL)
			{
				if (parsed == exit)
				{
					return 0;
				}

				in.push(parsed);
			}
		}
		connectors = build(in);		

		delete [] cstring;
	}

	return 0;
}

Rshell * buildTree(stack<Rshell *> & s)
{
	Rshell * root = NULL;
	Rshell * temp = NULL;
	while (!s.empty())
	{
		temp = s.top();
			
	}		
}

stack<Rshell *> build(stack<char*> & in)
{
	stack<Rshell *> c;

	string and_string = "&&";
	string or_string = "||";
	string always_string = ";";
	string comment_string = "#";

	//pop until we get a connector
	//put into temp stack
	stack<char *> temp_stack;
	while (!in.empty())
	{
		char * temp = in.top();
		temp_stack.push(in.top());
		in.pop();	
		//found a connector
		if (temp == and_string)
		{
			//put other stack into char* []?
			Rshell * _and = new And(temp_stack);
			c.push(_and);
		}
		else if (temp == or_string)
		{
			Rshell * _or = new Or(temp_stack);
			c.push(_or);
		}
		else if (temp == always_string)
		{
			Rshell * _always = new Always(temp_stack);
			c.push(_always);
		}
		else if (temp == comment_string)
		{
			//do something
			cout << "break maybe?" << endl;
		}
	}
	//no connectors
	//need to combine the rest of the stuff for a command
	//and pass it into the command constructor
	/*
	if (!temp_stack.empty())
	{
		//char * test1 = combine(temp_stack);
		//Rshell * test = new Command(test1);
		Command * test = new Command(temp_stack);
		test->evaluate();
	}
	*/
	return c;
}

char * combine(stack<char*> s)
{
	//try combining all the char * then making them into
	//char * [] in the constructor, appears to work here

	char * temp = s.top();
	s.pop();
	while(!s.empty())
	{
		strcat(temp, s.top());
		s.pop();	
	}
	return temp;
}

void stack_print(stack<char *> s)
{
	while (s.size() > 0)
	{
		char * temp = s.top();
		cout << temp[0] << endl;
		s.pop();
	}
}
