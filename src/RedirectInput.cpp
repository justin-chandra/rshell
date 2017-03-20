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
	if (!s.empty())
	{
		path = s.top();
	}
}

bool RedirectInput::evaluate(int in, int out)
{
	in = open(path, O_RDONLY);
	return first->evaluate(in, out);
}

void RedirectInput::setFirst(Rshell * r)
{
	this->first = r;
}

Rshell * RedirectInput::getParent()
{
	return this->parent;
}
