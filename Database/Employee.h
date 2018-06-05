#pragma once
#include "Person.h"

class Employee : public Person {

protected:
	string department;
	int salary;
	int id;

public:
	Employee() {}; // constructor
	Employee(string _f_name, string _l_name, int _age, int _id): Person(_f_name, _l_name, _age), id(_id) {}; // constructor with parameters
	Employee(const Employee &e); // copying constructor

	void SetDepartment(string dept) { department = dept; };
	void SetSalary(int s) { salary = s; };
	void SetId(int n) { id = n; };
	
	const string GetDepartment() const { return department; };
	int GetSalary() const { return salary; };
	int GetId() const { return id; };

	virtual void Display(bool) const; // display employee object
	Employee& operator=(const Employee &e); // overloading assignment operator
};