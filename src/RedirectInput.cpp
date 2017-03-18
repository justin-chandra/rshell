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
	in = open(path, O_RDONLY);
	//cout << "in < : " << in << endl;
	//cout << "out < : " << out << endl;
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
