#include <iostream>
#include "Test.h"
#include "Command.h"
//note to self: includ sys call libraries
//use p error to figure out if the stat call works or not

using namespace std;

//we don't use this first constructor
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

//new constructor not in any other class
Test::Test(vector<char *> v)
{
	
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

//modified/different compared to other classes
//must be able to call that stat linux command
bool Test::evaluate()
{
	
}

//returns parent, sets parent, first, and second
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
