#include <iostream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <vector>
#include <boost/tokenizer.hpp>


using namespace std;

#include "Rshell.h"
#include "Connector.h"
#include "Command.h"

int main(int argc, char * argv[])
{	
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
		Command * c = new Command(input);
		c->evaluate();
		//delete c;
	} while(getline(cin, input));

	//old stuff below
	//boost::char_separator<char> sep(" ");
	//boost::tokenizer< boost::char_separator<char> > tok(input, sep);	
	/*
	   do
	   {

	   cout << username << "@" << hostname << "$ ";
	   boost::char_separator<char> sep(" ");
	   boost::tokenizer< boost::char_separator<char> > tok(input, sep);	

	//cout << username << "@" << hostname << "$ ";
	for (boost::tokenizer< boost::char_separator<char> >::iterator beg = tok.begin(); 
	beg != tok.end(); ++beg)
	{
	cout << *beg << endl;
	}

	} while (getline(cin, input));
	*/

	return 0;
}
