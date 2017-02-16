#include <iostream>

using namespace std;

#include "And.h"
#include "Command.h"

And::And(Rshell * f, Rshell * s)
{
	this->first = f;
	this->second = s;
}

And::And(stack<char *> s)
{
	Command * c = new Command(s);
	this->second = c;
}

And::And()
{

}

And::~And()
{

}

bool And::evaluate()
{
	if (first->evaluate() == true)
	{
		second->evaluate();
		status = true;
		return true;
	}
	else if (first->evaluate() == false)
	{
		status = false;
		return false;
	}	

	return false;
}

Rshell * And::getParent()
{
	return this->parent;
}

void And::setParent(Rshell * p)
{
	this->parent = p;
}

void And::setFirst(Rshell * f)
{
	this->first = f;
}

void And::setSecond(Rshell * s)
{
	this->second = s;
}

