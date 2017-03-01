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
	char * c = v.at(2);
	//what's been given in vector v is the command line argument
	//you only need the path file/stuff that comes after the flag
	//you need to make a char * that is the path to the file/directory you're checking
	//get the flag, and set it according to the second index of the command line argument
	//is v.(0) == test?
	//otherwise if symbols, you can knock off brackets
	//you need char * c to = the path/v.at(2)

	stat(c, &sb);	

	string testString = "test";
	string openingBracket = "[";
	string dashE = "-e";
	string dashF = "-f";
	string dashD = "-d";
	
	//change it so that test without a tag

	if (v.at(0) == testString || v.at(0) == openingBracket)
	{
		if (v.at(1) == dashE)
		{
			if (S_ISDIR(sb.st_mode) || S_ISREG(sb.st_mode))
			{
				//BREAK HERE TO CHECK
				cout << "(True)" << endl;
				return true;	
			}
		}

		if (v.at(1) == dashF)
		{
			if (S_ISREG(sb.st_mode))
			{
				cout << "(True)" << endl;
				return true;
			}
	
		}

		if (v.at(1) == dashD)
		{
			if (S_ISDIR(sb.st_mode))
			{
				cout << "(True)" << endl;
				return true;
			}
		}

	}
	cout << "(False)" << endl;
	return false;


/*	if (stat(c, &sb) == -1)
	{
		perror("stat");
		return false;
	}
*/
/*
	if (e)
	{
		if (S_ISDIR(sb.st_mode) || S_ISREG(sb.st_mode))
		{
			//BREAK HERE TO CHECK
			cout << "(True)" << endl;
			return true;	
		}
	}
	else if (f)
	{
		if (S_ISREG(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;
		}
	}
	else if (d)
	{
		if (S_ISDIR(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;
		}
	}
	return false;
	*/
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
