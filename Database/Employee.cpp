#include "Employee.h"

Employee::Employee(const Employee &e) // copying constructor
{
	department = e.department;
	salary = e.salary;
	id = e.id;
	f_name = e.f_name;
	l_name = e.l_name;
	age = e.age;
};

void Employee::Display(bool type) const
{
	if (type)
	{
		cout << "Employment type: employee" << endl;
		cout << "Id: " << id << endl;
		cout << f_name << " " << l_name << " age: " << age << " salary: " << salary << endl;
		cout << "Department: " << department << endl << endl;
	}
	else
	{
		cout << "\tEmployment type: employee" << endl;
		cout << "\tId: " << id << endl;
		cout << "\t" << f_name << " " << l_name << " age: " << age << " salary: " << salary << endl;
		cout << "\tDepartment: " << department << endl << endl;
	}
};

Employee &Employee::operator = (const Employee &e) // overloading assignment operator
{
	if (&e != this)
	{
		this->age = e.age;
		this->department = e.department;
		this->f_name = e.f_name;
		this->id = e.id;
		this->l_name = e.l_name;
		this->salary = e.salary;
	}
	return *this;
};
