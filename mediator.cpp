#include "mediator.h"

void UnitedNations::addCountry(Country* c)
{
	_c.push_back(c);
}

void UnitedNations::send(string msg)
{
	for (auto c : _c)
		c->notify(msg);
}


void America::notify(string msg)
{
	cout << "----America get msg : " << msg << endl;
}

void America::send(string msg)
{
	cout << "--America said \"" << msg << "\"" << endl;;
	un->send(msg);
}

void China::notify(string msg)
{
	cout << "----China get msg : " << msg << endl;
}

void China::send(string msg)
{
	cout << "--China said \"" << msg << "\"" << endl;;
	un->send(msg);
}


void Russia::notify(string msg)
{
	cout << "----Russia get msg : " << msg << endl;
}

void Russia::send(string msg)
{
	cout << "--Russia said \"" << msg << "\"" << endl;;
	un->send(msg);
}


void mediator_run()
{
	UnitedNations* un = new UnitedNations();
	America* a = new America(un);
	China* c = new China(un);
	Russia* r = new Russia(un);
	un->addCountry(a);
	un->addCountry(c);
	un->addCountry(r);

	r->send("美国, 别找事");
	a->send("二毛去干他");
	c->send("你们别打了");
}


