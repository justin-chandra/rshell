#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <vector>
#include <stack>

using namespace std;

#include "Rshell.h"
#include "Connector.h"
#include "Command.h"

int main(int argc, char * argv[])
{	
	stack<char *> in;	

	//gets username
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);	
	

	string input;
	while (1 == 1)
	{
		cout << username << "@" << hostname << "$ ";
		getline(cin, input);
		
		//converts to cstring
		char * cstring = new char[input.size() + 1];
		strcpy(cstring, input.c_str());
		
		char * parsed = strtok(cstring, " ");
		in.push(parsed);

		while (parsed != NULL)
		{
			parsed = strtok(NULL, " ");
			in.push(parsed);
		}

		Command * c = new Command(parsed);	

		delete [] cstring;
	}

	return 0;
}
