#pragma once
#include<iostream>
using namespace std;
/*
老系统太复杂了, 用一个类抱一下
*/


class SubSystemOne
{
public:
	void method_one()
	{
		cout << "method one" << endl;
	}
};


class SubSystemTwo
{
public:
	void method_two()
	{
		cout << "method two" << endl;
	}
};


class SubSystemThree
{
public:
	void method_three()
	{
		cout << "method three" << endl;
	}
};



class FacadeSystem
{
private:
	SubSystemOne* s1;
	SubSystemTwo* s2;
	SubSystemThree* s3;
public:
	FacadeSystem()
	{
		s1 = new SubSystemOne();
		s2 = new SubSystemTwo();
		s3 = new SubSystemThree();
	}
	void facade_method()
	{
		s1->method_one();
		s2->method_two();
		s3->method_three();
	}
};



void facade_run()
{
	FacadeSystem* fs = new FacadeSystem();
	fs->facade_method();
	delete fs;
}



