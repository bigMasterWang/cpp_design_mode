#pragma once
#include<iostream>
using namespace std;


class Singleton
{
private:
	static Singleton* _instance;
public:
	Singleton() {};
	static Singleton* getInstance()
	{
		if (_instance)
			_instance = new Singleton();
		return _instance;
	}
};


Singleton* Singleton::_instance = nullptr;


void singleton_run()
{
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	if (s1 == s2)
		cout << "singleton" << endl;
	else
		cout << "not singleton" << endl;
}


