#pragma once
#include<iostream>
using namespace std;
/*
代理模式
实际上和装饰模式原理都一样, 可以看作是装饰模式的一种具体应用
就是在核心类外面包一层代理
*/


class Interface
{
public:
	virtual void request() = 0;
};


class NetRequest : public Interface
{
public:
	virtual void request()
	{
		cout << "real net request";
	}
};


class NetProxy : public Interface
{
public:
	void request()
	{
		cout << "proxy" << endl;
		NetRequest* nr = new NetRequest();
		nr->request();
		delete nr;
	}
};


void proxy_run()
{
	NetProxy* np = new NetProxy();
	np->request();
	delete np;
}



