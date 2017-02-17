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

//stack<Rshell *> build(stack<char *> & in);
vector<Rshell *> build(stack<char *> & in);
void stack_print(stack<char *> s);
char * combine(stack<char *> s);
//Rshell * tree(stack<Rshell *> & s);
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
			//qin.push(parsed);
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
				//qin.push(parsed);
			}
		}
		//connectors = build(in);
		conn = build(in);
		//cout << conn.size() << endl;
		Rshell * root = tree(conn);
		if (root->evaluate() == -1)
		{
			return 0;
		}
		delete [] cstring;
	}

	return 0;
}

/*
Rshell * tree(stack<Rshell *> & s)
{
	Rshell * root = s.top();
	Rshell * temp = s.top();
	while (!s.empty())
	{
		temp = s.top();
		if (!root)
		{
			root->setFirst(temp);
			root = temp;
		}
		s.pop();
	}

	return root;		
}
*/
Rshell * tree(vector<Rshell *> & v)
{
	Rshell * root = v.at(v.size() - 1);
	Rshell * temp = root;
	v.pop_back();
	while (v.size() > 0)
	{
		//cout << v.size() << " root loop" << endl;
		temp = v.at(v.size() - 1);
		if (!root)
		{
			//root->setFirst(temp);
			temp->setFirst(root);
			root->setParent(temp);
			
			root = temp;
		}
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
		bool semicolon = false;
		//found a connector
		if (temp == and_string)
		{
			//put other stack into char* []?
			temp_stack.pop();
			Rshell * _and = new And(temp_stack);
			//cout << "Printing stack: ";
			//stack_print(temp_stack);
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
		else if (semicolon || ( temp == always_string))
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
/*
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
			empty_stack(temp_stack);
		}
		else if (temp == or_string)
		{
			Rshell * _or = new Or(temp_stack);
			c.push(_or);
			empty_stack(temp_stack);
		}
		else if (temp == always_string)
		{
			Rshell * _always = new Always(temp_stack);
			c.push(_always);
			empty_stack(temp_stack);
		}
		else if (temp == comment_string)
		{
			//do something
			cout << "early return" << endl;
			return c;
		}
		//empty_stack(temp_stack);
	}
	//no connectors
	//need to combine the rest of the stuff for a command
	//and pass it into the command constructor
	if (!temp_stack.empty())
	{
		if (c.empty())
		{
			//single command
			Command * single_command = new Command(temp_stack);
			c.push(single_command);
		}
		else if (!c.empty())
		{
			Command * last_command = new Command(temp_stack);
			Rshell * last_connector = c.top();
			//there is a segmentation fault when the 
			//the pop statement below is executed
			//try making a vector
			c.pop();
			//cout << last_connector->evaluate() << endl;
			last_connector->setFirst(last_command);
			c.push(last_connector);
		}
	}
	return c;
}
*/
void empty_stack(stack<char *> & s)
{
	while(!s.empty())
	{
		s.pop();
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
		cout << temp;
		s.pop();
	}
	cout << endl;
}
