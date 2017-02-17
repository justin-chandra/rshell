#include <iostream>

using namespace std;

#include "And.h"
#include "Command.h"

And::And(Rshell * f, Rshell * s)
{
	this->first = f;
	this->second = s;
}

And::And(Rshell * r)
{
	this->first = r->first;
	this->second = r->second;
	this->parent = r->getParent();
	this->status = r->status;
}

And::And(stack<char *> s)
{
	Command * c = new Command(s);
	this->second = c;
}

And::And(queue<char *> q)
{
	Command * c = new Command(q);
	this->first = c;
}

And::And()
{

}

And::~And()
{

}

bool And::evaluate()
{
	//evaluates left and right children
	if (first->evaluate() == true) 
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

	return true;
}
//the rest of these should be self explanatory based on the function name, but y'know... this sets first, second, and parent to... what first, second, and the parent are... and also enables you to get the parent... because rshell is going to need to be able to do that in order to function... yeah...
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

