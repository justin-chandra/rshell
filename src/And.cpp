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
