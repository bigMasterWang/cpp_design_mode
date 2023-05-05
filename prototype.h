#pragma once
#include<string>
#include<iostream>
using namespace std;
/*
��һ������copy����һ������, ������֪���κδ�����ϸ��, ������ߴ���������
*/



class ProtoBase
{
private:
	string name;
public:
	ProtoBase(string _n) : name(_n) {};
	ProtoBase() {};
	virtual ProtoBase* clone() { return nullptr; };
	void show()
	{
		cout << name << endl;
	}
};


class ConcreteProto : public ProtoBase
{
public:
	ConcreteProto() {};
	ConcreteProto(string _m) : ProtoBase(_m) {};
	ConcreteProto* clone()
	{
		ConcreteProto* p = new  ConcreteProto();
		*p = *this;
		return p;
	}
};


class ConcreteProto2 : public ProtoBase
{
public:
	ConcreteProto2() {};
	ConcreteProto2(string _m) : ProtoBase(_m) {};
	ConcreteProto2* clone()
	{
		ConcreteProto2* p = new ConcreteProto2();
		*p = *this;
		return p;
	}
};



void proto_run()
{
	ConcreteProto* c = new ConcreteProto("concrete proto");
	ConcreteProto2* c2 = (ConcreteProto2*)c->clone();
	c->show();
	c2->show();
}

