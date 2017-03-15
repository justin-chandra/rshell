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
			//looking for paren
			if (parsed[0] == '(')
			{
				unsigned j = 0;
				for (unsigned i = 1; parsed[i] != '\0'; ++i)
				{
					parsed[i - 1] = parsed[i];
					j = i;
				}
				parsed[j] = '\0';
				string op = "(";
				char * open_paren = new char[1];
				strcpy(open_paren, op.c_str());			
				in.push(open_paren);
			}

			bool insert_closing_paren = false;
			for (unsigned i = 0; parsed[i] != '\0'; ++i)
			{
				if (parsed[i] == ')')
				{
					parsed[i] = '\0';
					insert_closing_paren = true;
					break;
				}
			}
			bool semi_colon_exists = false;
			//looking for comment
			if (parsed[0] == '#')
			{
				break;
			}
			//looking for ';'
			for (unsigned i = 0; parsed[i] != '\0'; ++i)
			{
				if (parsed[i] == ';')
				{
					parsed[i] = '\0';
					semi_colon_exists = true;
					break;
				}
			}

			//inserts the ending characters
			in.push(parsed);
			if (semi_colon_exists)
			{
				string sc = ";";
				char * semicolon_string = new char[1];
				strcpy(semicolon_string, sc.c_str());
				in.push(semicolon_string);
			}

			if (insert_closing_paren)
			{
				string cp = ")";
				char * cp_string = new char[1];
				strcpy(cp_string, cp.c_str());
				in.push(cp_string);
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
	string closing_paren = ")";
	string opening_paren = "(";
	string pipe = "|";
	string inputRedirect = "<";
	string outputRedirectAppend = ">>";
	string outputRedirectOverwrite = ">";

	stack<char *> temp_stack;	

	while(!s.empty())
	{
		char * temp = s.top();
		temp_stack.push(s.top());
		s.pop();

		//ending parens
		if (temp == closing_paren)
		{
			queue<char *> q;
			temp_stack.pop();
			while (temp != opening_paren)
			{
				temp = s.top();
				s.pop();
				if (temp != opening_paren && temp != closing_paren)
				{
					q.push(temp);
				}
			}
			//print(q);
			Rshell * set_of_parens = build_parens(q);
			//attach the parens to connector

			if (!s.empty())
			{
				temp = s.top();
				s.pop();
			}
			if (temp == and_string)
			{
				Rshell * _and_ = new And();
				//_and_->setSecond(set_of_parens);
				connectors.push_back(_and_);
			}
			else if (temp == or_string)
			{
				Rshell * _or_ = new Or();
				//_or_->setSecond(set_of_parens);
				connectors.push_back(_or_);
			}
			else if (temp == always_string)
			{
				Rshell * _always_ = new Always();
				//_always_->setSecond(set_of_parens);
				connectors.push_back(_always_);
			}
			else if(temp == comment_string)
			{
				break;
			}
			else
			{
				connectors.push_back(set_of_parens);
			}
			//print(s);
		}
		else
		{
			//print(temp_stack);
			if (temp == and_string)
			{
				temp_stack.pop();
				Rshell * _and = new And(temp_stack);
				//print(temp_stack);
				connectors.push_back(_and);
				empty_stack(temp_stack);
			}
			else if (temp == or_string)
			{
				temp_stack.pop();
				Rshell * _or = new Or(temp_stack);
				//print(temp_stack);
				connectors.push_back(_or);
				empty_stack(temp_stack);
			}
			else if (temp == always_string)
			{
				temp_stack.pop();
				//print(temp_stack);
				Rshell * _always = new Always(temp_stack);
				connectors.push_back(_always);
				empty_stack(temp_stack);
			}
			else if (temp == pipe)
			{
				cout << "found pipe" << endl;
			}
			else if (temp == inputRedirect)
			{
				print(temp_stack);
				Rshell * inRedirect = new RedirectInput(temp_stack);
				connectors.push_back(inRedirect);
				empty_stack(temp_stack);
			}
			else if (temp == outputRedirectAppend)
			{
				/*
				Rshell * outputRedirectO = new OutputRedirectO(temp_stack);
				connectors.push_back(outputRedirectO);
				empty_stack(temp_stack);
				*/
			}
			else if (temp == outputRedirectOverwrite)
			{
				temp_stack.pop();
				temp_stack.push(s.top());
				s.pop();
				//print(temp_stack);
				Rshell * outputRedirectO = new OutputRedirectO(temp_stack);
				connectors.push_back(outputRedirectO);
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
		//print(temp_stack);
		if (connectors.empty())
		{
			Command * single_command = new Command(temp_stack);
			connectors.push_back(single_command);
		}
		else if (!connectors.empty())
		{
			Command * last_command = new Command(temp_stack);
			//connectors.back()->setFirst(last_command);
			connectors.at(connectors.size() - 1)->setFirst(last_command);
		}
	}
	//cout << "Size of connectors: " << connectors.size() << endl;
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

void Shell::print(queue<char *> q)
{
	cout << "Start Print: ";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << " :End Print" << endl;
}

void Shell::print(stack<char *> s)
{
	cout << "Start Print: ";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << " : End of Print" << endl;
}

void Shell::empty_stack(stack<char *> & s)
{
	while (!s.empty())
	{
		s.pop();
	}
}
