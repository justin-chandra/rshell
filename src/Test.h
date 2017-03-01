#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

#include "Connector.h"

#ifndef TEST_H
#define TEST_H

Class Test: public Connector
{
	public:
		Test(Rshell *, Rshell*)
		Test(Rshell *)
		Test(stack<char *>s);
		
		Test(vector<char *>v);		

		Test();
		~Test();

		Rshell * first;
		Rshell * second;
		Rshell * parent;
		string userInput;
		bool status;
		
		vector<char *> v;

		bool evaluate();
		
		Rshell * getParent();
		
		void setParent(Rshell *);
		void setFirst(Rshell *);
		void setSecond(Rshell *);
}

#endif
