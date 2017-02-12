#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
#include <boost/tokenizer.hpp>
#include <sys/wait.h>
#include <vector>

using namespace std;

#include "Command.h"

Command::Command()
{

}

Command::Command(string s)
{
	//cout << s;
	build(s);
	//stack_print();	
}

Command::Command(char * argument)
{
	strcpy(this->command, argument);
}

Command::~Command()
{
	delete first;
}

void Command::build(string input)
{
	boost::char_separator<char> sep(" ");
	boost::tokenizer< boost::char_separator<char> > tok(input, sep);
	for (boost::tokenizer< boost::char_separator<char> >::iterator beg = tok.begin();
			beg != tok.end(); ++beg)
	{
		string str = *beg;
		char * cstr = new char[str.length() + 1];
		strcpy(cstr, str.c_str());
		commands.push(cstr);
		delete [] cstr;
	}

	//make tree thing
	while (commands.size() > 0)
	{
		//pops off main stack and puts into temp stack to find connectors
		temp.push(commands.top());
		string item = commands.top();
		commands.pop();
		if (item == "&&" || item == "||" || item == ";" || item == "#") 
		{
			temp.pop();
		}
	}
	if (temp.size() > 0)
	{
		//command = temp.top();
		//temp.pop();
		while (temp.size() > 0)
		{
			args.push_back(temp.top());
			temp.pop();
		}	
		args.push_back(NULL);
	}
}

bool Command::evaluate()
{
	//pid_t parent = getpid();
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		cout << "Fork failed in: " << endl << "bool Command::evaluate()" << endl;
	}
	else if (child_pid > 0)
	{
		int status;
		waitpid(child_pid, &status, 0);
	}
	else 
	{
		char ** args_pointer = &args[0];
		/*
		   vector<char*> test;
		   test.push_back("echo");
		   test.push_back("test");
		   test.push_back(NULL);
		   char ** test2 = &test[0];
		   */
		char * command_check = args[0];
		cout << command_check[1] << endl;
		int i = 0;
		/*
		while(command_check[i] != '\n')
		{
			
		}
		*/
		execvp(args[0], args_pointer);
		//exit(0);
	}

	return false;
}

//test functions and stuff
void Command::stack_print(stack<char*> s)
{	
	while (s.size() > 0)
	{
		string str(s.top());
		s.pop();
	}
}
