#pragma once
#include "Employee.h"
#include <list>

class Manager : public Employee {

private:
	list<Person *> subordinates; // list of subordinates

public:
	Manager() {}; // constructor
	Manager(string _f_name, string _l_name, int _age, int _id) : Employee(_f_name, _l_name, _age, _id) {}; // constructor with parameters
	Manager(const Manager &m); // copying constructor
	Person* AddSubordinate(Person *p) { subordinates.push_back(p); return p; }; //add an employee to the subordinates list
	bool DeleteSubordinate(int id);
	virtual void Display(bool) const;
	void DisplaySubordinates() const;
	Manager& operator=(const Manager &m);
};