#pragma once
#include<iostream>
#include"WorkContext.h"
using namespace std;
/*
״̬ģʽ

һ���������״̬, �Ҳ�ͬ״̬�в�ͬ����Ϊ, ���������������һ��״̬���ʵ��
��ͬ״̬����Ϊ, ��״̬���л�, ����״̬��������н������


1. ǰ�õ�������, ֻ������û��ʹ�������ķ���(�������캯��)
2. ������ʹ�ø���Ĺ��췽��, ��������(����) : ������(����)
3. ����������໥����, ����.h��.cpp�ļ�����, ��Ҫ��д��.h��
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

