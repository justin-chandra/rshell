#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sys/wait.h>
#include <vector>
#include <stack>

using namespace std;
#include "Rshell.h"
#include "Command.h"

Command::Command()
{

}

Command::Command(stack<char *> s)
{
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	v.push_back('\0');
	/*
	cout << "Making: ";
	for (unsigned i = 0; v[i] != '\0'; ++i)
	{
		cout << v[i];
	}
	cout << endl;
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
		char ** vloc = &v[0];
		if (execvp(v.at(0), vloc) == -1)
		{
			//cout << "execvp in bool Command::evaluate() failed" << endl;
			cout << "-rshell: " << v.at(0) << ": command not found" << endl;
			return false;
			//return -1;
		}
	}
	else if (child_pid > 0)
	{
		int status;
		waitpid(child_pid, &status, 0);
		return true;
	}
	return true;
}


