#pragma once
#include<iostream>
using namespace std;
/*
�Ž�ģʽ
�ۺϱ�ʾһ������'ӵ��'��ϵ, ���ֵ���A������԰���B����, ��B������A�����һ����
�ϳ�����һ��ǿ��'ӵ��'��ϵ, �������ϸ�Ĳ��ֺ�����Ĺ�ϵ, ���ֺ��������������һ��
���   ---�ϳ�--->   ����   ---�ۺ�--->   ��Ⱥ
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
			cout << "��Ϊ�ֻ� " << getName() << endl;
			getSoft()->run();
		}
	};


	class XiaoMi : public PhoneBrand
	{
	public:
		XiaoMi(string n) : PhoneBrand(n) {};
		void run() override
		{
			cout << "С���ֻ� " << getName() << endl;
			getSoft()->run();
		}
	};


	void bridge_run()
	{
		HuaWei* hw = new HuaWei("��ҫ20s");
		XiaoMi* xm = new XiaoMi("����20s");
		Game* g = new Game("̰����");
		Mp3* m = new Mp3("���岥����");
		hw->setSoft(g);
		xm->setSoft(m);
		hw->run();
		xm->run();
	}



}



