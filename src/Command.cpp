#include <iostream>

using namespace std;

#include "Command.h"

Command::Command()
{

}

Command::Command(string s)
{
	//cout << s << endl;
}

Command::~Command()
{

}

bool Command::evaluate()
{
	return false;
}
