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

Command::Command(char * c)
{
	
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


