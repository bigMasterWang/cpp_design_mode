#pragma once
#include<iostream>
using namespace std;


/*
������ģʽ, manager����������, һ��process����, ���������ж��Լ��ܷ�ִ��, ���ܵĻ�, ���ϼ�ִ��
*/

class Request
{
private:
	int level;
public:
	Request(int l) : level(l) {};
	inline void setLevel(int l) { level = l; };
	inline const int getLevel() { return level; };
};

class Manager
{
private:
	Manager* superior;
public:
	void SetSuperior(Manager* m) { superior = m; };
	const Manager* getManager() const { return superior; };
	virtual void processRequest(Request* r) const = 0;
};

/*
const��������, ֻ��ִ��const���͵ķ���
cosst�ڷ�������, �൱��const this->, ����ָ�÷�����, thisִ�еķ�����������const��, ��������ʵ���ķ�����û��Ҫ��
*/

class Manager1 : public Manager
{
public:
	void processRequest(Request* r) const override
	{
		if (r->getLevel() < 10)
		{
			cout << "Manager1 processed" << endl;
		}
		else
		{
			cout << "Manager1 can not process \t";
			getManager()->processRequest(r);
		}
	}
};


class Manager2 : public Manager
{
public:
	void processRequest(Request* r) const override
	{
		if (r->getLevel() < 20)
		{
			cout << "Manager2 processed" << endl;
		}
		else
		{
			cout << "Manager2 can not process \t";
			getManager()->processRequest(r);
		}
	}
};


class Manager3 : public Manager
{
public:
	void processRequest(Request* r) const override
	{
		if (r->getLevel() < 30)
		{
			cout << "Manager3 processed" << endl;
		}
		else
		{
			cout << "Manager3 can not process \t";
		}
	}
};


void chain_of_reposibility_run()
{
	
	Manager1* m1 = new Manager1();
	Manager2* m2 = new Manager2();
	Manager3* m3 = new Manager3();
	m1->SetSuperior(m2);
	m2->SetSuperior(m3);
	
	Request* r = new Request(5);
	m1->processRequest(r);

	r->setLevel(15);
	m1->processRequest(r);

	r->setLevel(25);
	m1->processRequest(r);

	r->setLevel(35);
	m1->processRequest(r);
}






