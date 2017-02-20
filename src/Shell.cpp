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

		char * parsed = strtok(input_cstring, " ");
		while (parsed != NULL)
		{
			//cout << parsed << endl;
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
			else
			{
				in.push(parsed);
			}

			parsed = strtok(NULL, " ");
		}
		connectors = build(in);
		Rshell * root = build_tree(connectors);
		if (root != NULL)
		{
			root->evaluate();
		}
		delete [] input_cstring;
	}
}

Rshell * Shell::build_tree(vector<Rshell *> & v)
{
	Rshell * root = NULL;
	Rshell * temp = NULL;
	if (!v.empty())
	{
		root = v.back();
		temp = root;
		v.pop_back();
	}

	while(!v.empty())
	{
		temp = v.back();
		temp->setFirst(root);
		root->setParent(temp);

		root = temp;
		v.pop_back();
	}	

	return root;
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

		//ending parens
		if (temp[sizeof(temp) - 1] == ')')
		{
			temp[sizeof(temp) - 1] = '\0';
			//make queue to proceess parens
			queue<char *> q;
			q.push(temp);
			temp = s.top();
			while (temp[0] != '(' && !s.empty())
			{
				temp = s.top();
				s.pop();
				q.push(temp);
			}
			//removing last paren (
			char * last = new char[sizeof(temp) - 1];
			for (unsigned i = 1; temp[i] != '\0'; ++i)
			{
				last[i - 1] = temp[i];
			}
			q.push(last);
			Rshell * set_of_parens = build_parens(q);

			//attach the parens to connector
			temp = s.top();
			s.pop();
			if (temp == and_string)
			{
				Rshell * _and_ = new And();
				_and_->setSecond(set_of_parens);
				connectors.push_back(_and_);
			}
			else if (temp == or_string)
			{
				Rshell * _or_ = new Or();
				_or_->setSecond(set_of_parens);
				connectors.push_back(_or_);
			}
			else if (temp == always_string)
			{
				Rshell * _always_ = new Always();
				_always_->setSecond(set_of_parens);
				connectors.push_back(_always_);
			}
			else if(temp == comment_string)
			{
				break;
			}
		}
		else
		{
			if (temp == and_string)
			{
				temp_stack.pop();
				Rshell * _and = new And(temp_stack);
				connectors.push_back(_and);
				empty_stack(temp_stack);
			}
			else if (temp == or_string)
			{
				temp_stack.pop();
				Rshell * _or = new Or(temp_stack);
				connectors.push_back(_or);
				empty_stack(temp_stack);
			}
			else if (temp == always_string)
			{
				temp_stack.pop();
				Rshell * _always = new Always(temp_stack);
				connectors.push_back(_always);
				empty_stack(temp_stack);
			}
			else if(temp == comment_string)
			{
				break;
			}
		}
	}

	if (!temp_stack.empty())
	{
		if (connectors.empty())
		{
			Command * single_command = new Command(temp_stack);
			connectors.push_back(single_command);
		}
		else if (!connectors.empty())
		{
			Command * last_command = new Command(temp_stack);
			connectors.back()->setFirst(last_command);
		}
	}

	return connectors;
}

Rshell * Shell::build_parens(queue<char *> & q)
{
	vector<Rshell *> c;
	Rshell * root = NULL;
	string and_string = "&&";
	string or_string = "||";
	string always_string = ";";
	string comment_string = "#";	

	stack<char *> temp_stack;
	while (!q.empty())
	{
		char * temp = q.front();
		temp_stack.push(temp);
		q.pop();
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
		else if(temp == comment_string)
		{
			break;
		}

		if (!temp_stack.empty())
		{
			if (q.empty())
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
	}	

	root = build_tree(c);

	return root;
}

void Shell::print(stack<char *> s)
{
	cout << "printing" << endl;
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}

void Shell::empty_stack(stack<char *> & s)
{
	while (!s.empty())
	{
		s.pop();
	}
}
