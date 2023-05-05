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
��������ģʽ �� �򵥹���ģʽ
�򵥹����ǽ���һ������, ���ز�����Ӧ���ʵ��
��������ģʽ, �ǲ�ͬ�Ĺ������ز�ͬ��ʵ��, ������Ŀ����һ��һ

��������ģʽ����������ʵ����ѡ��Ȩ�ŵ��˿ͻ���, �ṹ�ڲ�ֻ��Ҫ��������һ��һ����
������µ����͵Ļ�, ����Ҫ�ı�ԭ������(���޸ķ��), ֻ��Ҫ���һ��������Ŀ����(����չ����)
һ������ֻ����һ��ʵ��, ��һְ��ԭ��
*/

















