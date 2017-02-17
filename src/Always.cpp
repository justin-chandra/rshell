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
	Command * c = new Command(s);
	this->second = c;
}

Always::~Always()
{

}

bool Always::evaluate()
{
	first->evaluate();
	second->evaluate();
	return true;
}

Rshell * Always::getParent()
{
	return this->parent;
}

void Always::setParent(Rshell * p)
{
	this->parent = p;
}

void Always::setFirst(Rshell * f)
{
	this->first = f;
}

void Always::setSecond(Rshell * s)
{
	this->second = s;
}

