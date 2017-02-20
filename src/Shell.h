#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#include "Rshell.h"
#include "And.h"
#include "Or.h"
#include "Command.h"
#include "Always.h"

#ifndef SHELL
#define SHELL

class Shell
{
	public:
	Shell();
	~Shell();

	void execute();
	vector<Rshell *> build(stack<char *> & in);

	//helpers
	void empty_stack(stack<char *> &s);

};

#endif
