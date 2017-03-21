#include <iostream>

using namespace std;

#include "OutputRedirectA.h"
#include "Command.h"

OutputRedirectA::OutputRedirectA(Rshell * f, Rshell * s)
{
	this->first = f;
	this->second = s;
}

OutputRedirectA::OutputRedirectA(Rshell * r)
{
	this->first = r->first;
	this->second = r->second;
	this->parent = r->getParent();
	this->status = r->status;	
}

OutputRedirectA::OutputRedirectA(stack<char *>s)
{
	Command * c = new Command(s);
	this->second = c;
	filePath = s.top();
}

OutputRedirectA::OutputRedirectA()
{

}

OutputRedirectA::~OutputRedirectA()
{

}

bool OutputRedirectA::evaluate(int in, int out)
{
	out = open(filePath, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	return first->evaluate(in, out);
}

Rshell * OutputRedirectA::getParent()
{
	return this->parent;
}

void OutputRedirectA::setParent(Rshell * p)
{
	this->parent = p;
}

void OutputRedirectA::setFirst(Rshell * f)
{
	this->first = f;
}

void OutputRedirectA::setSecond(Rshell *s)
{
	this->second = s;
} 


