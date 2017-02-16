#include <iostream>
//#include <stack>
//
using namespace std;

#include "Or.h"
#include "Command.h"

Or::Or(Rshell * f, Rshell * s)
{
	this->first = f;
	this->second = s;
}

Or::Or(stack<char *> s)
{
	Command *c = new Command(s);
	this->second = c;
}

Or::Or()
{

}

Or::~Or()
{

}

bool Or::evaluate()
{
	if (first->evaluate() == false)
	{
		second->evaluate();
		status = true;
		return true;
	}
	else
	{
		status = false;
		return false;
	}	

	return false;
}

Rshell * Or::getParent()
{
	return this->parent;
}

void Or::setParent(Rshell * p)
{
	this->parent = p;
}

void Or::setFirst(Rshell * f)
{
	this->first = f;
}

void Or::setSecond(Rshell *s)
{
	this->second = s;
}
