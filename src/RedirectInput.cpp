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
	
	return false;
}

Rshell * RedirectInput::getParent()
{
	return this->parent;
}
