#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Player
{
private:
	string name;
public:
	Player(string n) : name(n) {};
	void notify(string _f)
	{
		cout << "player " << name << " accept notify from " << _f << endl;
	}
};

class Game
{
private:
	vector<Player*> players;
	string g_name;
public:
	Game(string n) : g_name(n) {};
	void add(Player* p)
	{
		players.push_back(p);
	}
	void notify()
	{
		for (auto it = players.begin(); it != players.end(); it++)
		{
			(*it)->notify(g_name);
		}
	}
};


void observer_run()
{
	Game* g = new Game("GTA¢ö");
	Player* p1 = new Player("wxf");
	Player* p2 = new Player("fy");
	g->add(p1);
	g->add(p2);
	g->notify();
}


