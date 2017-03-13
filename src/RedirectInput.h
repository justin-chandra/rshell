#include <iostream>


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
		bool status;

		RedirectInput();
		RedirectInput(Rshell *, Rshell *);
		RedirectInput(Rshell *);
		
		bool evaluate();
		Rshell * getParent();
};

#endif
