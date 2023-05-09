#include"state.h"

void ForenoonState::work()
{
	if (getWorkContext()->get_hour() < 10)
	{
		cout << "not up to time to work" << endl;
	}
	else if (getWorkContext()->get_hour() < 12)
	{
		cout << "forenoon time to work" << endl;
	}
	else
	{
		getWorkContext()->setWorkState(new NoonState(getWorkContext()));
		getWorkContext()->getWorkState()->work();
		delete this;
	}

}


void NoonState::work()
{
	if (getWorkContext()->get_hour() < 13)
	{
		cout << "time to noon sleep" << endl;
	}
	else
	{
		getWorkContext()->setWorkState(new AfternoonState(getWorkContext()));
		getWorkContext()->getWorkState()->work();
		delete this;
	}
}

void AfternoonState::work()
{
	if (getWorkContext()->get_hour() < 18)
	{
		cout << "afternoon time, good to work" << endl;
	}
	else
	{
		getWorkContext()->setWorkState(new NightState(getWorkContext()));
		getWorkContext()->getWorkState()->work();
		delete this;
	}
}


void NightState::work()
{
	if (getWorkContext()->get_hour() < 19)
	{
		cout << "is time to dinner" << endl;
	}
	else
	{
		getWorkContext()->setWorkState(new afternightState(getWorkContext()));
		getWorkContext()->getWorkState()->work();
		delete this;
	}
}


void afternightState::work()
{
	if (getWorkContext()->get_hour() < 22)
	{
		cout << "time to relax" << endl;
	}
	else
	{
		getWorkContext()->setWorkState(new SleepState(getWorkContext()));
		getWorkContext()->getWorkState()->work();
		delete this;
	}
}

void SleepState::work()
{
	if (getWorkContext()->get_hour() < 24 || getWorkContext()->get_hour() < 10)
	{
		cout << "time to sleep" << endl;
	}
	else
	{
		getWorkContext()->setWorkState(new ForenoonState(getWorkContext()));
		getWorkContext()->getWorkState()->work();
		delete this;
	}
}


void state_run()
{
	WorkContext* wc = new WorkContext();
	wc->setWorkState(new ForenoonState(wc));

	wc->set_hour(9.0);
	wc->getWorkState()->work();

	wc->set_hour(11.0);
	wc->getWorkState()->work();

	wc->set_hour(12.5);
	wc->getWorkState()->work();


	wc->set_hour(14.0);
	wc->getWorkState()->work();


	wc->set_hour(18.5);
	wc->getWorkState()->work();


	wc->set_hour(19.0);
	wc->getWorkState()->work();

	wc->set_hour(22.0);
	wc->getWorkState()->work();
}