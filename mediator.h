#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
�н���ģʽ, ���Ϲ����, ����֮�䲻����ͨ��, ͨ���н������Ϲ�ͨ��, 
������פ���Ϲ�����(������), ���Ϲ�Ҳ�и�������(������)
�͹۲���ģʽ��������
�۲����Ǳ����Ķ���ֱ�Ӱ���������, û�е�����, �Ǹ���֮��Ĵ�ʹ��
*/

class Country;

class UnitedNations
{
public:
	vector<Country*> _c;
	void addCountry(Country* c);
	void send(string msg);
};


class Country
{
public:
	UnitedNations* un;
	Country(UnitedNations* _un) : un(_un) {};
	virtual void send(string msg) = 0;
	virtual void notify(string msg) = 0;
};


class America : public Country
{
public:
	America(UnitedNations* _un) : Country(_un) {};
	void notify(string msg) override;
	void send(string msg) override;
};

class China : public Country
{
public:
	China(UnitedNations* _un) : Country(_un) {};
	void notify(string msg) override;
	void send(string msg) override;
};

class Russia : public Country
{
public:
	Russia(UnitedNations* _un) : Country(_un) {};
	void notify(string msg) override;
	void send(string msg) override;
};

void mediator_run();