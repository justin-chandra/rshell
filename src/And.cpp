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

And::And()
{

}

And::~And()
{

}

/*
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
*/

bool And::evaluate()
{
	if (first->evaluate())
	{
		return true;
	}
	else
	{
		return second->evaluate();
	}	
}

//returns parent
Rshell * And::getParent()
{
	return this->parent;
}

//gets parent, first, and second
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

