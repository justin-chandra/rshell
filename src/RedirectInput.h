#include <iostream>
#include <stack>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

#include "Connector.h"

#ifndef REDIRIN
#define REDIRIN

class RedirectInput: public Connector
{
	public:
		Rshell * first;
		Rshell * second;
		Rshell * parent;
		char * path;
		bool status;

		RedirectInput();
		RedirectInput(Rshell *, Rshell *);
		RedirectInput(Rshell *);
		RedirectInput(stack<char*>);
		
		bool evaluate(int in, int out);
		void setFirst(Rshell *);
		Rshell * getParent();
};

#endif
