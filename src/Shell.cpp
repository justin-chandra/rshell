#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <vector>
#include <stack>

using namespace std;

#include "Shell.h"
#include "Rshell.h"
#include "And.h"
#include "Or.h"
#include "Always.h"
#include "Command.h"

Shell::Shell()
{

}

Shell::~Shell()
{

}

void Shell::execute()
{
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
	if (gethostname(hostname, HOST_NAME_MAX) != 0)
	{
		perror("hostname");
	}
	if (getlogin_r(username, LOGIN_NAME_MAX) != 0)
	{
		perror("username");
	}

	stack <char *> in;
	while (1 == 1)
	{
		string input;
		vector<Rshell *> connectors;
		
		//bash output
		cout << username << "@" << hostname << "$ ";
		getline(cin, input);

		//get user input and convert to cstring
		char * input_cstring = new char[input.size() + 1];
		strcpy(input_cstring, input.c_str());

		while (strtok(input_cstring, " ") != NULL)
		{
			char * parsed = strtok(input_cstring, " ");

			//looking for comment
			if (parsed[0] == '#')
			{
				break;
			}

			//looking for ';'
			if (parsed[sizeof(parsed) - 1] == ';')
			{
				string sc = ";";
				char * semicolon_string = new char[1];
				strcpy(semicolon_string, sc.c_str());
				parsed[sizeof(parsed) - 1] = '\0';
				in.push(parsed);
				in.push(semicolon_string);
			}

			
		}
	}
	vector<Rshell *> connectors = build(in);
}

vector<Rshell*> Shell::build(stack<char *> & s)
{
	vector<Rshell *> connectors;
	string and_string = "&&";
	string or_string = "||";
	string always_string = ";";
	string comment_string = "#";

	stack<char *> temp_stack;

	while(!s.empty())
	{
		char * temp = s.top();
		temp_stack.push(s.top());
		s.pop();
		if (temp[sizeof(temp) - 1] == ')')
		{
			
		} 	
	}
		
	return connectors;
}

void Shell::empty_stack(stack<char *> & s)
{

}
