#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <pwd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "Test.h"
#include "Rshell.h"

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
	this->v = v;	
}

Test::Test(stack<char *>s)
{

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
	struct stat sb;
	char * c = new char[v.size()];
	if(stat(c, &sb)== -1)
	{
		perror("stat");
	}

	if (S_ISDIR(sb.st_mode) && S_ISREG(sb.st_mode))
	{
		cout << "(True)" << endl;
		return true;
	}
	else if(S_ISDIR(sb.st_mode))
	{
		//BREAK HERE TO CHECK
		cout << "(True)" << endl;
		cout << "Temporary cout: Is directory." << endl;
		return true;	
	}
	else if(S_ISREG(sb.st_mode))
	{
		cout << "(True)" << endl;
		cout << "Temporary cout: Is a regular file." << endl;
		return true;
	}
	else
	{
		cout << "(False)" << endl;
		return false;
	}
	return false;
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
