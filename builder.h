#pragma once
#include<iostream>
#include<string>
using namespace std;


/*
������ģʽ ʵ�ʲ����� �� ���ģʽ����, ������װһЩ����
ֻ������������װ����һ����Ĳ�ͬ����, ���ģʽ��װ������ɢ�Ĳ�ͬ��Ĳ�ͬ����
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