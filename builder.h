#pragma once
#include<iostream>
#include<string>
using namespace std;


/*
建造者模式 实际操作中 和 外观模式很像, 就是组装一些方法
只不过建造者组装的是一个类的不同方法, 外观模式组装的是零散的不同类的不同方法
*/


class PersonA
{
private:
	string head;
	string body;
	string root;
public:
	void construct_head(string _h)
	{
		head = _h;
	};
	void construct_body(string  _b)
	{
		body = _b;
	}
	void construct_root(string _r)
	{
		root = _r;
	}
	void show()
	{
		cout << "head: " << head << endl;
		cout << "body: " << body << endl;
		cout << "root: " << root << endl;
	}
};


class Builder
{
public:
	PersonA* build_person()
	{
		PersonA* p = new PersonA();
		p->construct_head("builder head");
		p->construct_body("builder body");
		p->construct_root("builder root");
		return p;
	}
};


void build_run()
{
	Builder* b = new Builder();
	PersonA* p = b->build_person();
	p->show();
}