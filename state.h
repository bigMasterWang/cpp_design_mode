#pragma once
#include<iostream>
#include"WorkContext.h"
using namespace std;
/*
状态模式

一个类会区分状态, 且不同状态有不同的行为, 则在这个类中声明一个状态类的实例
不同状态的行为, 和状态的切换, 都在状态类的子类中进行设计


1. 前置的类声明, 只适用于没有使用这个类的方法(包括构造函数)
2. 派生类使用父类的构造方法, 派生类名(参数) : 父类名(参数)
3. 如果两个类相互引用, 区分.h和.cpp文件即可, 不要都写在.h里
*/


class WorkState
{
private:
	WorkContext* wc;
public:
	WorkState() {};
	WorkState(WorkContext* _wc) : wc(_wc) {}; 
	WorkContext* getWorkContext() { return wc; };
	virtual void work()=0;
};



class ForenoonState : public WorkState 
{
public:
	ForenoonState(WorkContext* _wc) : WorkState(_wc) {};
	void work() override;
};


class NoonState : public WorkState
{
public:
	NoonState(WorkContext* _wc) : WorkState(_wc) {};
	void work() override;
};


class AfternoonState : public WorkState
{
public:
	AfternoonState(WorkContext* _wc) : WorkState(_wc) {};
	void work() override;
};


class NightState : public WorkState
{
public:
	NightState(WorkContext* _wc) : WorkState(_wc) {};
	void work() override;
};

class afternightState : public WorkState
{
public:
	afternightState(WorkContext* _wc) : WorkState(_wc) {};
	void work() override;
};


class SleepState : public WorkState
{
public:
	SleepState(WorkContext* _wc) : WorkState(_wc) {};
	void work() override;
};





void state_run();

