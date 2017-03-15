#include "RedirectInput.h"

RedirectInput::RedirectInput()
{

}

RedirectInput::RedirectInput(Rshell * first, Rshell * second)
{
	
}

RedirectInput::RedirectInput(Rshell * second)
{
	this->second = second;
}

RedirectInput::RedirectInput(stack<char*> s)
{
	
	s.pop();
	path = s.top();
}

bool RedirectInput::evaluate()
{
	int in = 0; //supposed to be parameter
	in = open(path, O_RDONLY);
	cout << in << endl;
	//dup2(in, 0);
	//return second->evaluate(in, out);
	return false;
	//return second->evaluate();
}

Rshell * RedirectInput::getParent()
{
	return this->parent;
}
