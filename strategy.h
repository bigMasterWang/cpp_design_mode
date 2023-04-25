#pragma once

#include<iostream>

class Operator
{
public:
	int first;
	int second;
	virtual int getResult() { return 0; };
};


class AddOperator : public Operator
{
	int gerResult()
	{
		return first + second;
	}
};


class MulOperator : public Operator
{
	int getResult()
	{
		return first * second;
	}
};


class Context
{
public:
	Operator* op;
	Context(char s, int a, int b)
	{
		if (s == '+')
			op = new AddOperator();
		else
			op = new MulOperator();

		op->first = a;
		op->second = b;
	}

	int gerResult()
	{
		return op->getResult();
	}
};


void run()
{
	using namespace std;
	Context* c = new Context('+', 1, 2);
	cout << c->gerResult() << endl;
}











