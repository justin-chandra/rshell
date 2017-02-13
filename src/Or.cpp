#include <iostream>

using namespace std;

#include "Or.h"

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
		status == true;
		return true;
	}
	
	else
	{
		status = false;
		return false;
	}	

	return false;
}
