#include <iostream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <boost/tokenizer.hpp>


using namespace std;

#include "Rshell.h"
#include "Connector.h"
#include "Command.h"

int main(int argc, char * argv[])
{	
	//Command * c = new Command("hi");

	//gets username
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);	
	
	//gets input
	string input;
	do
	{
		cout << username << "@" << hostname << "$ ";
		
	} while (getline(cin, input));

	return 0;
}
