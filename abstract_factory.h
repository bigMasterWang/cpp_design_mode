#pragma once
#include<string>
#include<iostream>
using namespace std;
/*
�򵥹���ģʽ: ����Ŀ����ķ���, ��ȡʵ��
��������ģʽ: ��ͬ�Ĺ������ز�ͬ��ʵ��, ������Ŀ����һ��һ
���󹤳�ģʽ: ����һϵ����ػ��໥�����Ľӿ�, һ������ͬʱ�����໥�й�����ͬһ������Ĳ�ͬ���ʵ��
*/


/*
�麯����, �������ʵ����ʹת���˻����ʵ��, �麯����Ȼʹ�õ����������,�麯���ʹ��麯����������
�麯���Ĳ����ͷ�������, ������Ҳ�����޸�
*/


namespace AbstracyFactory
{
	class Student
	{
	public:
		virtual void learn() = 0;
	};


	class Teacher
	{
	public:
		virtual void teach(Student* s) = 0;
	};


	class Factory
	{
	public:
		virtual Student* createStudent() = 0;
		virtual Teacher* createTeacher() = 0;
	};


	class PrimaryStudent : public Student
	{
	public:
		void learn()
		{
			cout << "I am a primary school student" << endl;
		}
	};


	class UniversityStudent : public Student
	{
	public:
		void learn()
		{
			cout << "I am a university student" << endl;
		}
	};


	class PrimaryTeacher : public Teacher
	{
	public:
		void teach(Student* s) override
		{
			cout << "I am a primary school teacher" << endl;
			s->learn();
		}
	};


	class UniversityTeacher : public Teacher
	{
	public:
		void teach(Student* s) override
		{
			cout << "I am a university teacher" << endl;
			s->learn();
		}
	};



	class PrimarySchoolFactory : public Factory
	{
	public:
		Student* createStudent() override
		{
			return new PrimaryStudent();
		}
		Teacher* createTeacher() override
		{
			return new PrimaryTeacher();
		}
	};


	class UniversityFactory : public Factory
	{
	public:
		Student* createStudent() override
		{
			return new UniversityStudent();
		}
		Teacher* createTeacher() override
		{
			return new UniversityTeacher();
		}
	};


	void abstract_factory_run()
	{
		UniversityFactory* factory = new UniversityFactory();
		//PrimarySchoolFactory* factory = new PrimarySchoolFactory();
		Student* s = factory->createStudent();
		Teacher* t = factory->createTeacher();
		t->teach(s);
	}

}
