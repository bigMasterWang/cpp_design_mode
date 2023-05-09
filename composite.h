#pragma once
#include<iostream>
#include<vector>
using namespace std;
/*
���ģʽ:
��������ϳ����νṹ�Ա�ʾ'����-����'�Ĳ�νṹ. ���ģʽʹ���û��Ե����������϶����ʹ�þ���һ����

*/
class Component
{
private:
	string name;
public:
	Component(string n) : name(n) {};
	inline string getName() { return name; };
	virtual void add_component(Component* c) = 0;
	virtual void display(int depth) = 0;
};


class Leaf : public Component
{
public:
	Leaf(string n) : Component(n) {};
	void add_component(Component* c) override
	{
		cout << "Leaf can not add component" << endl;
	}
	void display(int depth) override
	{
		for (int i = 0; i < depth; i++)
			cout << '-';
		cout << getName() << endl;
	}
};


class Composite : public Component
{
private:
	vector<Component*> _components;
public:
	Composite(string n) : Component(n) {};
	void add_component(Component* c) override
	{
		_components.push_back(c);
	}
	void display(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << '-';
		cout << getName() << endl;
		for (auto c : _components)
		{
			c->display(depth + 2);
		}
	}
};


void composite_run()
{
	Composite* c1 = new Composite("��˾");
	Composite* d1 = new Composite("����1");
	Composite* d2 = new Composite("����2");
	Composite* e1 = new Composite("Ա��1");
	Composite* e2 = new Composite("Ա��2");
	Composite* e3 = new Composite("Ա��3");
	Composite* e4 = new Composite("Ա��4");
	c1->add_component(d1);
	c1->add_component(d2);
	d1->add_component(e1);
	d1->add_component(e2);
	d2->add_component(e3);
	d2->add_component(e4);
	c1->display(0);
}