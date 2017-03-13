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

bool RedirectInput::evaluate()
{
	return false;
}

Rshell * RedirectInput::getParent()
{
	return this->parent;
}
