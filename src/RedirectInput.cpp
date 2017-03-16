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
	path = s.top();
}

bool RedirectInput::evaluate(int in, int out)
{
	in = open(path, O_RDONLY | S_IRUSR);
	return first->evaluate(in, 1);
}

void RedirectInput::setFirst(Rshell * r)
{
	this->first = r;
}

Rshell * RedirectInput::getParent()
{
	return this->parent;
}
