#include <iostream>

using namespace std;

#include "Command.h"
#include "Always.h"

Always::Always()
{

}

/*Always::Always (Rshell *f, Rshell *s)
{
	this->first = f;
	this->second = s;
}
*/

Always::Always(stack<char *> s)
{
	Command *c = new Command(s);
	this->second = c;
}

Always::~Always()
{

}

bool Always::evaluate()
{
	return true;
}
