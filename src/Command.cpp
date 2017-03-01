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
#include "Test.h"

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
	
	string test = "test";
	string open_bracket = "[";
	string e = "-e";
	string f = "-f";
	string d = "-d";
	if ((v.at(0) == test || v.at(0) == open_bracket) && v.size() >= 2)
	{
		Test * t = new Test(v);
		if (t->evaluate())
		{
			return false;
		}
		return true;
	}

	//execvp stuff
	pid_t child_pid = fork();
	//forks the current process to execute additional processes
	if (child_pid < 0)
	{
		perror("fork failure");
		return true;
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
	else 
	{
		//handles exit status and wait error
		if (waitpid(child_pid, &status, WUNTRACED) == 1)
		{
			perror("wait failed");
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status))

		{
			if (waitpid(child_pid, &status, WUNTRACED) == 1)
			{
				perror("wait failed");
			}
		}
		return status;
	}
	return true;
}


