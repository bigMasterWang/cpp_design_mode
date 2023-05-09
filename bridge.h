#pragma once
#include<iostream>
using namespace std;
/*
桥接模式
聚合表示一种弱的'拥有'关系, 体现的是A对象可以包含B对象, 但B对象不是A对象的一部分
合成则是一种强的'拥有'关系, 体现了严格的部分和整体的关系, 部分和整体的生命周期一样
翅膀   ---合成--->   大雁   ---聚合--->   雁群
*/


namespace BRIDGE
{
	class PhoneSoft
	{
	private:
		string name;
	public:
		PhoneSoft(string n) : name(n) {};
		inline string getName() { return name; };
		virtual void run() = 0;
	};


	class PhoneBrand
	{
	private:
		PhoneSoft* pf;
		string name;
	public:
		PhoneBrand(string n) : name(n) {};
		inline string getName() { return name; };
		inline PhoneSoft* getSoft() { return pf; };
		void setSoft(PhoneSoft* p) { pf = p; };
		virtual void run() = 0;
	};


	class Game : public PhoneSoft
	{
	public:
		Game(string n) : PhoneSoft(n) {};
		void run() override
		{
			cout << "software Game : " << getName() << endl;
		}
	};

	class Mp3 : public PhoneSoft
	{
	public:
		Mp3(string n) : PhoneSoft(n) {};
		void run() override
		{
			cout << "software Mp3 : " << getName() << endl;
		}
	};


	class HuaWei : public PhoneBrand
	{
	public:
		HuaWei(string n) : PhoneBrand(n) {};
		void run() override
		{
			cout << "华为手机 " << getName() << endl;
			getSoft()->run();
		}
	};


	class XiaoMi : public PhoneBrand
	{
	public:
		XiaoMi(string n) : PhoneBrand(n) {};
		void run() override
		{
			cout << "小米手机 " << getName() << endl;
			getSoft()->run();
		}
	};


	void bridge_run()
	{
		HuaWei* hw = new HuaWei("荣耀20s");
		XiaoMi* xm = new XiaoMi("红米20s");
		Game* g = new Game("贪吃蛇");
		Mp3* m = new Mp3("超清播放器");
		hw->setSoft(g);
		xm->setSoft(m);
		hw->run();
		xm->run();
	}



}



