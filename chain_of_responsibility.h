#pragma once
#include<iostream>
using namespace std;


/*
责任链模式, manager类自我连接, 一个process方法, 根据条件判断自己能否执行, 不能的话, 就上级执行
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
const返回类型, 只能执行const类型的方法
cosst在方法后面, 相当于const this->, 就是指该方法中, this执行的方法都必须是const的, 但是其他实例的方法并没有要求
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






