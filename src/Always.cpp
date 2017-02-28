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
	//and this...evaluates the children
	first->evaluate();
	second->evaluate();
	return true;
}

Rshell * Always::getParent()
{
	//this...returns the parent
	return this->parent;
}

void Always::setParent(Rshell * p)
{
	//this...SETS the parent
	this->parent = p;
}

void Always::setFirst(Rshell * f)
{
	//and THIS...SETS THE FIRST CHILD
	this->first = f;
}

void Always::setSecond(Rshell * s)
{
	//AND THIS. IT SETS THE SECOND CHILD.
	this->second = s;
}

