#pragma once
#include<iostream>
using namespace std;


class LeiFeng
{
public:
	void sweep()
	{
		cout << "leifeng sweep" << endl;
	}
};


class Student : public LeiFeng
{
public:
	void sweep()
	{
		cout << "student sweep" << endl;
	}
};


class Volunteer : public LeiFeng
{
public:
	void sweep()
	{
		cout << "volunteer sweep" << endl;
	}
};


class LeiFengFactory
{
public:
	LeiFeng* getLeiFeng()
	{
		return nullptr;
	}
};


class StudentFactory : LeiFengFactory
{
public:
	Student* getLeiFeng()
	{
		return new Student();
	}
};


class VolunteerFactory : LeiFengFactory
{
	Volunteer* getLeiFeng()
	{
		return new Volunteer();
	}
};


void factory_method_run()
{
	StudentFactory sf;
	LeiFeng* s = sf.getLeiFeng();
	s->sweep();
}

/*
工厂方法模式 和 简单工厂模式
简单工厂是接收一个参数, 返回参数对应类的实例
工厂方法模式, 是不同的工厂返回不同的实例, 工厂和目标类一对一

工厂方法模式把生成哪种实例的选择权放到了客户端, 结构内部只需要工厂和类一对一即可
添加了新的类型的话, 不需要改变原来的类(对修改封闭), 只需要添加一个工厂和目标类(对扩展开放)
一个工厂只生产一种实例, 单一职责原则
*/

















