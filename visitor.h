#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
������ģʽ, ���ǽ���Ϊ��ִ����Ϊ�Ķ���ֿ�, ��һ�������ִ����, ����ִ�е���Ϊ, ִ�е�ʱ����
��Ϊ������, ����ִ���ߵĲ���, ������Ϊ��ִ����Ҳ�ֿ���, ִ����Ҳ����֪����Ϊ
��Ϊ �� ִ���߾ͷֿ���, ͨ��ִ�е�ʱ���뼴��, �����߼�����
void run(Action a)
{
for p : perple:
	a(p);
}
����ֻ���������ݽṹ�ȶ���ϵͳ��, Ƶ���Ķ��Ͳ�̫����, ��Ϊ����Ϊȥ��ȡִ���ߵ�����, ����ϵͳ���ݽṹҪ�ȶ�
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
			cout << "ѧ��" << s->getName() << " ѧӢ��" << endl;
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
		Student* s1 = new Student("С��");
		Student* s2 = new Student("С��");
		Student* s3 = new Student("С��");
		Student* s4 = new Student("С��");
		EnglishTeacher* et = new EnglishTeacher();
		et->addStudent(s1);
		et->addStudent(s2);
		et->addStudent(s3);
		et->addStudent(s4);
		LearnEnglish* le = new LearnEnglish();
		et->teach(le);
	}


}



