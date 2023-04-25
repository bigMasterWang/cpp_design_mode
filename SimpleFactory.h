#pragma once
#include <iostream>
using namespace std;


class COperator
{
public:
    int first;
    int second;
    virtual int getResult() { return 0; };
};


class AddOperator : public COperator
{
public:
    int getResult()
    {
        return first + second;
    }
};


class MulOperator : public COperator
{
public:
    int getResult()
    {
        return first * second;
    }
};


class OperatorFactory
{
public:
    COperator* getOperator(char op);
};


COperator* OperatorFactory::getOperator(char op)
{
    COperator* res;
    if (op == '+')
        res = new AddOperator();
    else
        res = new MulOperator();
    return res;
}

void run()
{
    OperatorFactory* of = new OperatorFactory();
    COperator* op = of->getOperator('+');
    op->first = 1;
    op->second = 2;
    cout << op->getResult() << endl;
}