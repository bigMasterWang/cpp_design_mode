#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
访问者模式, 就是将行为和执行行为的对象分开, 用一个类管理执行者, 具体执行的行为, 执行的时候传入
行为方法中, 传入执行者的参数, 这样行为和执行者也分开了, 执行者也不用知道行为
行为 和 执行者就分开了, 通过执行的时候传入即可, 核心逻辑如下
void run(Action a)
{
for p : perple:
	a(p);
}
但是只适用于数据结构稳定的系统中, 频繁改动就不太行了, 因为是行为去获取执行者的属性, 所以系统数据结构要稳定
*/

namespace VISITOR
{
	class Student
	{
	private:
		string name;
	public:
		Student(string n) : name(n) {};
		const inline string getName() { return name; };
	};


	class Action
	{
	public:
		virtual void action(Student* s) = 0;
	};

	class LearnEnglish : public Action
	{
	public:
		void action(Student* s) override
		{
			cout << "学生" << s->getName() << " 学英语" << endl;
		}
	};


	class EnglishTeacher
	{
	private:
		vector<Student*> _s;
	public:
		void addStudent(Student* s)
		{
			_s.push_back(s);
		}
		void teach(Action* l)
		{
			for (auto s : _s)
				l->action(s);
		}
	};



	void visitor_run()
	{
		Student* s1 = new Student("小李");
		Student* s2 = new Student("小明");
		Student* s3 = new Student("小红");
		Student* s4 = new Student("小刚");
		EnglishTeacher* et = new EnglishTeacher();
		et->addStudent(s1);
		et->addStudent(s2);
		et->addStudent(s3);
		et->addStudent(s4);
		LearnEnglish* le = new LearnEnglish();
		et->teach(le);
	}


}



