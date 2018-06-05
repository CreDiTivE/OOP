#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"
#include <fstream>
#include <vector>

class Database {

private:
	vector<Person*> employees;

public:
	Database() {};
	~Database() {}; // no need in destructor
	
	void LoadFromFile(const char *file); //creates “flat” database
	void ArrangeSubordinates(); //arranges "flat" database after loading from the file
	Person* HireEmployee(Person *p); //hire a new employee
	bool FireEmployee(int id); //fire the employee
	void DisplayDepartmentEmployees(string _department) const;
	void DisplayAll() const;
	vector<Person*> SQL(const char *field, const char * cond, const char* value);
	void ShowRecordSet(vector<Person*> rs);
};