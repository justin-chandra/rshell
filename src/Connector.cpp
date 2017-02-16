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

bool Connector::evaluate()
{
	return false;
}

Rshell * Connector::getParent()
{
	return this->parent;	
}

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

