#include <iostream>

using namespace std;

#include "Pipe.h"

Pipe::Pipe(Rshell * f, Rshell *s)
{
	this->first = f;
	this->second = s;
}

Pipe::Pipe(Rshell *r)
{
	this->first = r->first;
	this->second = r->second;
	this->parent = r->getParent();
	this->status = r->status;
}

Pipe::Pipe(stack<char *> s)
{
	Command * c = new COmmand(s);
	this->second = c;
}

Pipe::Pipe()
{

}

Pipe::~Pipe()
{

}

bool Pipe::evaluate()
{

}

Rshell * Pipe::getParent()
{
	return this->parent;
}

void Pipe::setParent(Rshell * p)
{
	this->parent = p;
}

void Pipe::setFirst(Rshell *f)
{
	this->first = f;
}

void Pipe::setSecond(Rshell *s)
{
	this->second = s;
}
