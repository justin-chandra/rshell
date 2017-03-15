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
	this->v = c->getVector();
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
	FILE * in;
	char buff[512];
	if (!(in = popen(v.at(0), "w")))
	{
		perror("popen");
	}

	while (fgets(buff, sizeof(buff), in) != NULL)
	{
		cout << buff;
	}

	pclose(in);
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
