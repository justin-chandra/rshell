#include <iostream>
#include "Test.h"
#include "Command.h"

using namespace std;

Test::Test(Rshell *f, Rshell *s)
{
	this->first = f;
	this->second = s;
}

Test::Test(Rshell *r)
{
	this->first = r->first;
	this->second = r->second;
	this->parent = r->getParent();
	this->status = r->status;
}

Test::Test(stack<char *>s)
{
	Command * c = new Command(s);
	this->second = c;
}

Test::Test()
{

}

Test::~Test()
{

}

bool Test::evaluate()
{

}

Rshell * Test::getParent()
{
	return this->parent;
}

void Test::setParent(Rshell *p)
{
	this->parent = p;
}

void Test::setFirst(Rshell *f)
{
	this->first = f;
}

void Test::setSecond(Rshell *s)
{
	this->second = s;
}
