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
	args[0] = temp;
}

Command::~Command()
{

}

bool Command::evaluate()
{
	//pid_t parent = getpid();
	string exit = "exit";
	int status;
	if (!v.empty())
	{
		if (v.at(0) == exit)
		{
			//_exit(1);
			std::exit(1);
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
			//the or issue with first thing is taken care of if the line below
			//is taken out
			_exit(-1); 
			//cout << "returning false in execvp if" << endl;
			//return false;
		}
		//_exit(1);
		//cout << "returning true" << endl;
		//return true;
	}
	else if (child_pid > 0)
	{
		waitpid(child_pid, &status, 0);
		/*
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			return status;
		}
		*/
	}
	return true;
}


