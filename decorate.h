#pragma once
#include<string>
#include<iostream>
using namespace std;
/*
装饰模式
当添加的功能不是类的核心功能时, 或者只有某些特殊情况才会走的逻辑, 
就不好直接添加到类中, 放到一个单独的修饰类中

最好修饰类能够直接继承目标类, 这样使用的方法也都一样了, 客户使用也不会有什么区别
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










