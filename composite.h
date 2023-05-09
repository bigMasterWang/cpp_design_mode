#pragma once
#include<iostream>
#include<vector>
using namespace std;
/*
组合模式:
将对象组合成树形结构以表示'部分-整体'的层次结构. 组合模式使得用户对单个对象和组合对象的使用具有一致性

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
	Composite* c1 = new Composite("公司");
	Composite* d1 = new Composite("部门1");
	Composite* d2 = new Composite("部门2");
	Composite* e1 = new Composite("员工1");
	Composite* e2 = new Composite("员工2");
	Composite* e3 = new Composite("员工3");
	Composite* e4 = new Composite("员工4");
	c1->add_component(d1);
	c1->add_component(d2);
	d1->add_component(e1);
	d1->add_component(e2);
	d2->add_component(e3);
	d2->add_component(e4);
	c1->display(0);
}