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
	Command * c = new Command(s);
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
	//change to have int in and int out parameters
	//int in, out;
	/*
	   pipefd[0] is the read end of the pipe
	   pipefd1[1] is the write end of the pipe
	   */
	
	//finish operations (read/write)
	//close(in/out);
	return false;
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
