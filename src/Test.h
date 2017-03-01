#include <iostream>
/*
#include <stack>
#include <string>
#include <queue>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
*/
#include <sys/types.h>
#include <pwd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

using namespace std;

#include "Rshell.h"
#include "And.h"
#include "Or.h"
#include "Always.h"

#ifndef TEST_H
#define TEST_H

class Test: public Rshell
{
	public:
		Test(Rshell *, Rshell*);
		Test(Rshell *);
		Test(stack<char *>s);
		
		Test(vector<char *> v);		

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
};

#endif
