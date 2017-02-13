#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sys/wait.h>
#include <vector>
#include <stack>

using namespace std;

#include "Command.h"

Command::Command()
{

}

Command::Command(stack<char*> s)
{
	unsigned i = 0;
	while(!s.empty())
	{
		//args[i] = s.top();
		//s.pop();	
		char * temp = s.top();
		args[i] = temp;
		++i;
		//cout << s.top() << endl;
		s.pop();
	}
	/*
	for (unsigned j = 0; j < 100; ++j)
	{
		cout << args[j] << endl;
	}
	*/
}

Command::Command(char * temp)
{
	/*
	for (unsigned i = 0; temp[i] != '\0'; ++i)
	{
		args[i] = temp[i];
	}
	*/
	args[0] = temp;
}

Command::~Command()
{

}

bool Command::evaluate()
{
	//pid_t parent = getpid();
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		cout << "Fork failed in: " << endl << "bool Command::evaluate()" << endl;
	}
	else if (child_pid == 0)
	{
		//cout << args[1] << endl;
		if (execvp(args[0], args) == -1)
		{
			cout << "execvp in bool Command::evaluate() failed" << endl;
			return -1;
		}
	}
	else if (child_pid > 0)
	{
		int status;
		waitpid(child_pid, &status, 0);
	}
	return false;
}


