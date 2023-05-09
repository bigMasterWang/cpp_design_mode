#pragma once
#include<iostream>
#include<vector>

using namespace std;
/*
命令模式, 总体来说, 就是一个命令类, 一个执行类, 执行类是命令类的一个属性
一个总的控制类, 有一个命令类的列表
*/

class Executer
{
public:

	void executeCmdOne()
	{
		cout << "Executer execute One" << endl;
	};
	void executeCmdTwo()
	{
		cout << "Executer execute Two" << endl;
	};
};

class BaseCommand
{
public:
	Executer* e;
	BaseCommand(Executer* _e) : e(_e) {};
	virtual void executeCmd()=0;
};


class CommandOne : public BaseCommand
{
public:
	CommandOne(Executer* e) : BaseCommand(e) {};
	void executeCmd() override
	{
		e->executeCmdOne();
	}
};


class CommandTwo : public BaseCommand
{
public:
	CommandTwo(Executer* e) : BaseCommand(e) {};
	void executeCmd() override
	{
		e->executeCmdTwo();
	}
};

class CommandManager
{
private:
	vector<BaseCommand*> _cmds;
public:
	void addCommand(BaseCommand* b)
	{
		_cmds.push_back(b);
	}
	void execute()
	{
		for (auto a : _cmds)
			a->executeCmd();
	}
};


void command_run()
{
	CommandManager* cm = new CommandManager();
	Executer* e = new  Executer();
	CommandOne* c1 = new CommandOne(e);
	CommandTwo* c2 = new CommandTwo(e);
	cm->addCommand(c1);
	cm->addCommand(c2);
	cm->execute();
}