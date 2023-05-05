#pragma once
#include<iostream>
using namespace std;
/*
����ģʽ
ʵ���Ϻ�װ��ģʽԭ��һ��, ���Կ�����װ��ģʽ��һ�־���Ӧ��
�����ں����������һ�����
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



