#include <iostream>

#include "Connector.h"
#include "Rshell.h"

using namespace std;
Connector::Connector()
{

}

Connector::~Connector()
{

}

//the default response is false here
bool Connector::evaluate()
{
	return false;
}

//returns parent
Rshell * Connector::getParent()
{
	return this->parent;	
}

//set parent and children
void Connector::setParent(Rshell * p)
{
	this->parent = p;	
}

void Connector::setFirst(Rshell * f)
{
	this->first = f;	
}

void Connector::setSecond(Rshell * s)
{
	this->second = s;	
}

