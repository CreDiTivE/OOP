#include "Manager.h"

Manager::Manager(const Manager &m) // copying constructor
{
	this->f_name = m.f_name;
	this->l_name = m.l_name;
	this->age = m.age;
	this->id = m.id;
}

Manager &Manager::operator = (const Manager &m) // overloading assignment operator
{
	if (&m != this)
	{
		this->f_name = m.f_name;
		this->l_name = m.l_name;
		this->age = m.age;
		this->id = m.id;
	}
	return *this;
}


bool Manager::DeleteSubordinate(int id)
{
	for (list<Person*>::iterator it = subordinates.begin(); it != subordinates.end(); ++it)
	{
		if (dynamic_cast<Employee*>(*it)->GetId() == id)
		{
			subordinates.erase(it);
			return true;
		}
	}
	return false;
}

void Manager::Display(bool type) const
{
	cout << "Employment type: manager" << endl;
	cout << "Id: " << id << endl;
	cout << f_name << " " << l_name << " age: " << age << " salary: " << salary << endl;
	cout << "Department: " << department << endl;
	DisplaySubordinates();
};

void Manager::DisplaySubordinates() const
{
	cout << "Subordinates:" << endl;
	if (subordinates.empty())
		cout << "\tList of subordinates is empty." << endl << endl;
	else
	{
		for (list<Person*>::const_iterator it = subordinates.begin(); it != subordinates.end(); ++it)
		{
			Employee* emp = dynamic_cast<Employee*>(*it);
			emp->Display(false);
		}
	}
}
