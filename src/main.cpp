#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include "Rshell.h"
#include "Connector.h"

#include "And.h"
#include "Or.h"
#include "Always.h"
#include "Command.h"

vector<Rshell *> build(stack<char *> & in);
void stack_print(stack<char *> s);
Rshell * tree(vector<Rshell *> & v);
void empty_stack(stack<char *> & s);

int main(int argc, char * argv[])
{	
	stack<char *> in;

	queue<char *> qin;

	//gets username
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);	

	string comment = "#";
	string input;
	while (1 == 1)
	{
		stack<Rshell *> connectors;
		vector<Rshell *> conn;
		//queue<Rshell *> connectors;
		cout << username << "@" << hostname << "$ ";
		getline(cin, input);

		//converts to cstring
		char * cstring = new char[input.size() + 1];
		strcpy(cstring, input.c_str());

		char * parsed = strtok(cstring, " ");

		string sc = ";";
		char * semicolon_string = new char[1];
		strcpy(semicolon_string, sc.c_str());		

		if (parsed != NULL)
		{
			in.push(parsed);
		}
		while (parsed != NULL)
		{
			bool semicolon = false;
			parsed = strtok(NULL, " ");
			if (parsed != NULL)
			{
				if (parsed == comment)
				{
					break;
				}
				if (strlen(parsed) > 0)
				{
					if (parsed[0] == '#')
					{
						break;

					}
					//find the semicolon at the end of the string
					/*
					if (strlen(parsed) > 1)
					{
						if (parsed[strlen(parsed) - 1] == ';')
						{
							cout << "end: " << parsed[strlen(parsed) - 1] << endl;
							parsed[strlen(parsed) - 1] = '\0';

							cout << "No semi: " << parsed << endl;
							semicolon = true;
						}
					}
					*/
				}
				in.push(parsed);
				if (semicolon)
				{
					//it only works if there are two invalid strings
					//sdfsdf sdfsdf; echo a 
					//works
					in.push(semicolon_string);
				}
			}
		}
		conn = build(in);
		Rshell * root = tree(conn);
		if (root != NULL)
		{
			root->evaluate();
		}
		delete [] cstring;
	}
	return 0;
}

Rshell * tree(vector<Rshell *> & v)
{
	Rshell * root = NULL;
	Rshell * temp = NULL;
	if (!v.empty())
	{
		root = v.back();
		temp = root;
		v.pop_back();
	}
	while (!v.empty())
	{
		temp = v.back();
		temp->setFirst(root);
		root->setParent(temp);

		root = temp;
		v.pop_back();
	}
	return root;
}

vector<Rshell *> build(stack<char *> & in)
{
	vector<Rshell *> c;
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
		/*
		   for (unsigned i = 0; i < strlen(temp); ++i)
		   {
		   if (temp[i] == ';')
		   {
		   temp[i] = '\0';
		   cout << "found ; " << endl;
		   Rshell * always = new Always(temp_stack);
		   c.push_back(always);
		   break;	
		   }
		   }
		   */
		if (temp == and_string)
		{
			temp_stack.pop();
			Rshell * _and = new And(temp_stack);
			c.push_back(_and);
			empty_stack(temp_stack);
		}
		else if (temp == or_string)
		{
			temp_stack.pop();
			Rshell * _or = new Or(temp_stack);
			c.push_back(_or);
			empty_stack(temp_stack);
		}
		else if (temp == always_string)
		{
			temp_stack.pop();
			Rshell * _always = new Always(temp_stack);
			c.push_back(_always);
			empty_stack(temp_stack);
		}
		else if (temp == comment_string)
		{
			break;
		}
	}

	if (!temp_stack.empty())
	{
		if (c.empty())
		{
			Command * single_command = new Command(temp_stack);
			c.push_back(single_command);
		}
		else if (!c.empty())
		{
			Command * last_command = new Command(temp_stack);
			c.at(c.size() - 1)->setFirst(last_command);
		}
	}
	return c;
}

void empty_stack(stack<char *> & s)
{
	while(!s.empty())
	{
		s.pop();
	}
}

void stack_print(stack<char *> s)
{
	while (s.size() > 0)
	{
		char * temp = s.top();
		cout << temp;
		s.pop();
	}
	cout << endl;
}
