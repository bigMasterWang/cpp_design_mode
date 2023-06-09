#pragma once
#include<string>
#include<iostream>
using namespace std;
/*
简单工厂模式: 输入目标类的符号, 获取实例
工厂方法模式: 不同的工厂返回不同的实例, 工厂和目标类一对一
抽象工厂模式: 创建一系列相关或相互依赖的接口, 一个工厂同时创建相互有关联的同一流程里的不同类的实例


补充:
工厂方法模式是, 一个工厂创建一个特定的目标实例
抽象工厂模式是, 一个工厂, 创建一系列的相关的不同实列

比如class user对用户表进行操作, class department对部门表进行操作
只对用户表进行操作的时候, 一个mysql, 一个oracle 两个工厂, 都生产user类, 就可以了
如果加了一个department类, 那么用抽象工厂
mysql的工厂类, 既能创建user类, 又能创建department类, 就是抽象工厂方法类了
*/


/*
虚函数表, 派生类的实例即使转成了基类的实例, 虚函数仍然使用的是派生类的,虚函数和纯虚函数都是这样
虚函数的参数和返回类型, 派生类也不能修改
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
