#pragma once
#include<iostream>
using namespace std;

class BaseMan
{
public:
	void show() 
	{
		cout << "I am " << getName() << endl;
	}
protected:
	virtual string getName()
	{
		return "BaseMan";
	}
};


class ManOne : public BaseMan
{
protected:
	string getName()
	{
		return "ManOne";
	}
};

class ManTwo : public BaseMan
{
protected:
	string getName()
	{
		return "ManTwo";
	}
};



void template_method_run()
{
	ManOne* m1 = new ManOne();
	ManTwo* m2 = new ManTwo();
	m1->show();
	m2->show();

}








