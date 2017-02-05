#include <iostream>

using namespace std;

#include "Rshell.h"

#ifndef Command_H
#define Command_H

class Command: public Rshell
{
	public:
		Rshell * first;
		Rshell * second;
		string userInput;
		bool status;
		Command();
		Command(string s);
		~Command();
		bool evaluate();
	private:
};

#endif
