#pragma once
#include<string>
#include<iostream>
using namespace std;
/*
װ��ģʽ
����ӵĹ��ܲ�����ĺ��Ĺ���ʱ, ����ֻ��ĳЩ��������Ż��ߵ��߼�, 
�Ͳ���ֱ����ӵ�����, �ŵ�һ����������������

����������ܹ�ֱ�Ӽ̳�Ŀ����, ����ʹ�õķ���Ҳ��һ����, �ͻ�ʹ��Ҳ������ʲô����
*/

class Person
{
private:
	string name;
public:
	Person(string n) : name(n) {};
	Person() {};
	virtual void show() { cout << "my name is : " << name << endl; };
};



class Finery : public Person
{
public:
	Person* dp;
	virtual void show() { dp->show(); };
	void decorate(Person* p) { dp = p; };
};


class TShirt : public Finery
{
public:
	void show()
	{
		cout << "this is TShirt" << endl;
		dp->show();
	}
};


class Trousers : public Finery
{
public:
	void show()
	{
		cout << "This is Trousers" << endl;
		dp->show();
	}
};



void decorate_run()
{
	Person p("william");
	TShirt t1;
	Trousers t2;
	t2.decorate(&t1);
	t1.decorate(&p);
	t2.show();
}










