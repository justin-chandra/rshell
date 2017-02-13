#include <iostream>

using namespace std;

#include "And.h"

And::And(Rshell * f, Rshell * s)
{
	this->first = f;
	this->second = s;
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
