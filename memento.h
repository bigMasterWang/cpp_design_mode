#pragma once
#include<iostream>
using namespace std;


class Memo
{
private:
	int state;
public:
	inline int getState() { return state; };
	Memo(int s) : state(s) {};
};


class Target
{
private:
	int state;
public:
	Target(int s) : state(s) {};
	void setState(int s)
	{
		state = s;
	}
	void show()
	{
		cout << "state: " << state << endl;
	}

	Memo* createMemo()
	{
		return new Memo(state);
	}

	void setMemo(Memo* m)
	{
		state = m->getState();
	}
};


class MemoTaker
{
public:
	Memo* m;
};



void memo_run()
{
	Target* t = new Target(2);
	MemoTaker* mt = new MemoTaker();
	mt->m = t->createMemo();
	t->show();
	t->setState(12);
	t->show();
	t->setMemo(mt->m);
	t->show();
}