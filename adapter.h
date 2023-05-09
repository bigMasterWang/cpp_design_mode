#pragma once
#include<iostream>
#include<string>
using namespace std;

/*
������Ŀ���������һ����������, ���ڼ�������������
*/

namespace ADAPTER
{
	class Player
	{
	private:
		string name;
	public:
		Player() {};
		Player(string n) : name(n) {};
		inline string getName() { return name; };
		virtual void attack() = 0;
	};


	class PlayerA : public Player
	{
	public:
		PlayerA(string n) : Player(n) {};
		void attack() override
		{
			cout << "Player A " << getName() << "attack" << endl;
		}
	};


	class PlayerB : public Player
	{
	public:
		PlayerB(string n) : Player(n) {};
		void attack() override
		{
			cout << "���B " << getName() << "����" << endl;
		}
	};

	class PlayerBAdapter : public Player
	{
	private:
		PlayerB* pb;
	public:
		PlayerBAdapter(PlayerB* b) : pb(b) {};
		void attack() override
		{
			pb->attack();
			cout << "Player B" << pb->getName() << "attack" << endl;
		}
	};


	void adapter_run()
	{
		PlayerA* a = new  PlayerA("wxf");
		PlayerBAdapter* pba = new PlayerBAdapter(new PlayerB("����"));
		a->attack();
		pba->attack();
	}


}