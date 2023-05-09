#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
中介者模式, 联合国大会, 各国之间不互相通信, 通过中介者联合国通信, 
各国有驻联合国代理(有属性), 联合国也有各国代理(有属性)
和观察者模式的区别呢
观察者是被订阅对象直接包含订阅者, 没有第三方, 是各国之间的大使馆
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