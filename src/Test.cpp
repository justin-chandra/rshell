#include "Test.h"

//we don't use this first constructor
Test::Test(Rshell *f, Rshell *s)
{
	this->first = f;
	this->second = s;
}

Test::Test(Rshell *r)
{
	this->first = r->first;
	this->second = r->second;
	this->parent = r->getParent();
	this->status = r->status;
}

//new constructor not in any other class
Test::Test(vector<char *> v)
{
	this->v = v;	
	e = false;
	d = false;
	f = false;
}

Test::Test(stack<char *>s)
{

}

Test::Test()
{

}

Test::~Test()
{

}

bool Test::evaluate(int in, int out)
{
	string dashE = "-e";
	string dashF = "-f";
	string dashD = "-d";
	string open_bracket = "[";
	string test = "test";

	struct stat sb;
	char * c = NULL;

	if (dup2(in, 0) == -1)
	{
		perror("dup2");
		return false;
	}	

	if (dup2(out, 1) == -1)
	{
		perror("dup2 2");
		return false;
	}

	//decides the flag
	if (v.size() == 0)
	{
		cout << "(False)" << endl;
		return false;
	}
	if (v.at(0) == open_bracket)
	{
		if (v.size() == 5)
		{
			c = v.at(2);
			if (v.at(1) == dashE)
			{
				e = true;
			}
			else if (v.at(1) == dashF)
			{
				f = true;
			}
			else if (v.at(1) == dashD)
			{
				d = true;
			}
		}
		else if (v.size() == 4)
		{
			c = v.at(1);
			e = true;
		}
		else 
		{
			cout << "(False)" << endl;
			return false;
		}
	}
	else if (v.at(0) == test)
	{
		if (v.size() == 4)
		{
			c = v.at(2);
			if (v.at(1) == dashE)
			{
				e = true;
			}
			else if (v.at(1) == dashF)
			{
				f = true;
			}
			else if (v.at(1) == dashD)
			{
				d = true;
			}
		}
		else if (v.size() == 3)
		{
			c = v.at(1);
			e = true;
		}
		else
		{
			cout << "(False)" << endl;
			return false;
		}
	}
	
	stat(c, &sb);	

	//assigns the actual tag
	if (e)
	{
		if (S_ISDIR(sb.st_mode) || S_ISREG(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;	
		}
	}
	else if (f)
	{
		if (S_ISREG(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;
		}
	}
	else if (d)
	{
		if (S_ISDIR(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;
		}
	}
	cout << "(False)" << endl;
	return false;
}


bool Test::evaluate()
{
	string dashE = "-e";
	string dashF = "-f";
	string dashD = "-d";
	string open_bracket = "[";
	string test = "test";

	struct stat sb;
	char * c = NULL;

	//decides the flag
	if (v.size() == 0)
	{
		cout << "(False)" << endl;
		return false;
	}
	if (v.at(0) == open_bracket)
	{
		if (v.size() == 5)
		{
			c = v.at(2);
			if (v.at(1) == dashE)
			{
				e = true;
			}
			else if (v.at(1) == dashF)
			{
				f = true;
			}
			else if (v.at(1) == dashD)
			{
				d = true;
			}
		}
		else if (v.size() == 4)
		{
			c = v.at(1);
			e = true;
		}
		else 
		{
			cout << "(False)" << endl;
			return false;
		}
	}
	else if (v.at(0) == test)
	{
		if (v.size() == 4)
		{
			c = v.at(2);
			if (v.at(1) == dashE)
			{
				e = true;
			}
			else if (v.at(1) == dashF)
			{
				f = true;
			}
			else if (v.at(1) == dashD)
			{
				d = true;
			}
		}
		else if (v.size() == 3)
		{
			c = v.at(1);
			e = true;
		}
		else
		{
			cout << "(False)" << endl;
			return false;
		}
	}
	
	stat(c, &sb);	

	//assigns the actual tag
	if (e)
	{
		if (S_ISDIR(sb.st_mode) || S_ISREG(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;	
		}
	}
	else if (f)
	{
		if (S_ISREG(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;
		}
	}
	else if (d)
	{
		if (S_ISDIR(sb.st_mode))
		{
			cout << "(True)" << endl;
			return true;
		}
	}
	cout << "(False)" << endl;
	return false;
}

//returns parent, sets parent, first, and second
Rshell * Test::getParent()
{
	return this->parent;
}

void Test::setParent(Rshell *p)
{
	this->parent = p;
}

void Test::setFirst(Rshell *f)
{
	this->first = f;
}

void Test::setSecond(Rshell *s)
{
	this->second = s;
}
