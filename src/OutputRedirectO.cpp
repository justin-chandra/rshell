#include <iostream>

using namespace std;

#include "OutputRedirectO.h"
#include "Command.h"

OutputRedirectO::OutputRedirectO(Rshell * f, Rshell * s)
{
	this->first = f;
	this->second = s;
}

OutputRedirectO::OutputRedirectO(Rshell * r)
{
	this->first = r->first;
	this->second = r->second;
	this->parent = r->getParent();
	this->status = r-status;
}

OutputRedirectO::OutputRedirectO(stack<char *>s)
{
	Command *c = new Command(s);
	this->second = c;
}

OutputRedirectO::OutputRedirectO()
{

}

OutputRedirectO::~OutputRedirectO()
{

}

bool OutputRedirectO::evaluate()
{
	//just for now
	return false;	
}

Rshell * OutputRedirectO::getParent()
{
	return this->parent;
}

void OutputRedirectO::setParent(Rshell * p)
{
	this->parent = p;
}  

void OutputRedirectO::setFirst(Rshell *f)
{
	this->first = f;
}

void OutputRedirectO::setSecond(Rshell *s)
{
	this->second = s;
}
