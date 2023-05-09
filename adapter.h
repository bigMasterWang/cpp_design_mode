#pragma once
#include<iostream>
#include<string>
using namespace std;

/*
就是在目标类外面包一层适配器类, 用于兼容整个程序框架
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
			cout << "玩家B " << getName() << "进攻" << endl;
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
		PlayerBAdapter* pba = new PlayerBAdapter(new PlayerB("龙斌"));
		a->attack();
		pba->attack();
	}


}