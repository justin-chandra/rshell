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

Command::Command(stack<char *> s)
{
	//builds the command into a vector<char*>
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	v.push_back('\0');
}

Command::~Command()
{

}

bool Command::evaluate()
{
	//evaulates the command in vector
	string exit = "exit";
	int status;
	if (!v.empty())
	{
		//if the exit command is called
		if (v.at(0) == exit)
		{
			_exit(1);
		}
	}
	pid_t child_pid = fork();
	//forks the current process to execute additional processes
	if (child_pid < 0)
	{
		perror("fork failure");
	}
	else if (child_pid == 0)
	{
		//executes the given command
		char ** vloc = &v[0];
		if (execvp(v.at(0), vloc) == -1)
		{
			//cout << "-rshell: " << v.at(0) << ": command not found" << endl;
			perror("execvp");
			_exit(1); 
		}
	}
	else if (child_pid > 0)
	{
		//handles exit status and wait error
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("wait failed");
		}
		if (WEXITSTATUS(status) != 0)
		{
			return false;
		}
	}
	return true;
}


