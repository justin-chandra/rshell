#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sys/wait.h>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>

using namespace std;

#include "Rshell.h"
#include "Command.h"

Command::Command()
{

}

Command::Command(queue<char *> q)
{
	while (!q.empty())
	{
		v.push_back(q.front());
		q.pop();
	}
	v.push_back('\0');
}

Command::Command(stack<char *> s)
{
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	v.push_back('\0');
}

Command::Command(char * temp)
{
	args[0] = temp;
}

Command::~Command()
{

}

bool Command::evaluate()
{
	string exit = "exit";
	int status;
	if (!v.empty())
	{
		if (v.at(0) == exit)
		{
			_exit(1);
		}
	}
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		cout << "Fork failed in: " << endl << "bool Command::evaluate()" << endl;
	}
	else if (child_pid == 0)
	{
		char ** vloc = &v[0];
		if (execvp(v.at(0), vloc) == -1)
		{
			cout << "-rshell: " << v.at(0) << ": command not found" << endl;
			_exit(1); 
		}
	}
	else if (child_pid > 0)
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			//cout << "wait error" << endl;
		}
		if (WEXITSTATUS(status) != 0)
		{
			return false;
		}
	}
	return true;
}


