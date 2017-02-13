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
#include "Command.h"

void build(stack<char *> & in);
void stack_print(stack<char *> s);
char * combine(stack<char *> s);

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
		cout << username << "@" << hostname << "$ ";
		getline(cin, input);

		//converts to cstring
		char * cstring = new char[input.size() + 1];
		strcpy(cstring, input.c_str());

		char * parsed = strtok(cstring, " ");
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
			if (parsed == exit)
			{
				return 0;
			}
			if (parsed != NULL)
			{
				in.push(parsed);
			}
		}
		//stack print for testing
		//stack_print(in);
		build(in);		

		delete [] cstring;
	}

	return 0;
}

void build(stack<char*> & in)
{
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
			Rshell * conn = new And();
		}
		else if (temp == or_string)
		{

		}
		else if (temp == always_string)
		{

		}
		else if (temp == comment_string)
		{

		}
	}
	//no connectors
	//need to combine the rest of the stuff for a command
	//and pass it into the command constructor
	if (!temp_stack.empty())
	{
		//char * test1 = combine(temp_stack);
		//Rshell * test = new Command(test1);
		Rshell * test = new Command(temp_stack);
		test->evaluate();
	}
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
