#include "Database.h"

void Database::ShowRecordSet(vector<Person*> rs)
{
	for (vector<Person*>::const_iterator it = rs.begin(); it != rs.end(); ++it)
	{
		dynamic_cast<Employee *>(*it)->Display(true);
	}
};

vector<Person*> Database::SQL(const char *field, const char * cond, const char* value)
{
	vector<Person*> tmp;
	cout << "~~~~~~~~ Selected by " << field;
	if (cond == "gt") cout << " grate than ";
	else if (cond == "lt") cout << " less than ";
	else if (cond == "eq") cout << " is equal ";
	cout << value << " ~~~~~~~~\n\n";
	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); ++it)
	{
		if ((field == "department" && dynamic_cast<Employee*>(*it)->GetDepartment() == value) ||
			(field == "salary" &&
			((cond == "gt" && dynamic_cast<Employee*>(*it)->GetSalary() > atoi(value)) ||
				(cond == "lt" && dynamic_cast<Employee*>(*it)->GetSalary() < atoi(value)) ||
				(cond == "eq" && dynamic_cast<Employee*>(*it)->GetSalary() == atoi(value)))) ||
				(field == "id" &&
			((cond == "gt" && dynamic_cast<Employee*>(*it)->GetId() > atoi(value)) ||
					(cond == "lt" && dynamic_cast<Employee*>(*it)->GetId() < atoi(value)) ||
				(cond == "eq" && dynamic_cast<Employee*>(*it)->GetId() == atoi(value)))) ||
				(field == "age" &&
			((cond == "gt" && dynamic_cast<Employee*>(*it)->GetAge() > atoi(value)) ||
					(cond == "lt" && dynamic_cast<Employee*>(*it)->GetAge() < atoi(value)) ||
				(cond == "eq" && dynamic_cast<Employee*>(*it)->GetAge() == atoi(value))))
			) {
			tmp.emplace_back(dynamic_cast<Employee*>(*it));
		}
	}
	return tmp;
}


void Database::LoadFromFile(const char *file) //creates “flat” database
{
	ifstream datafile(file);
	if (!datafile) throw "Error opening file.";
	if (datafile.peek() == EOF) throw "File is empty.";

	char str[256], f_name[64], l_name[64], department[32];
	int type, id, age, salary;

	while (!datafile.eof())
	{
		datafile.getline(str, 256);
		type = atoi(strtok(str, ";"));
		id = atoi(strtok(NULL, ";"));
		strcpy(f_name, strtok(NULL, ";"));
		strcpy(l_name, strtok(NULL, ";"));
		age = atoi(strtok(NULL, ";"));
		strcpy(department, strtok(NULL, ";"));
		salary = atoi(strtok(NULL, ";"));
		if (type == 0)
		{
			Employee* tmp = new Employee(f_name, l_name, age, id);
			tmp->SetDepartment(department);
			tmp->SetSalary(salary);
			employees.emplace_back(tmp);
		}
		else if (type == 1)
		{
			Manager* tmp = new Manager(f_name, l_name, age, id);
			tmp->SetDepartment(department);
			tmp->SetSalary(salary);
			employees.emplace_back(tmp);
		}
	}
	datafile.close();
}

void Database::ArrangeSubordinates() //arranges "flat" database after loading from the file
{
	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); ++it)
	{
		if (typeid(**it) == typeid(Manager))
		{
			for (vector<Person*>::iterator it2 = employees.begin(); it2 != employees.end(); ++it2)
			{
				if (typeid(**it2) == typeid(Employee) && dynamic_cast<Manager*>(*it)->GetDepartment() == dynamic_cast<Employee*>(*it2)->GetDepartment())
				{
					dynamic_cast<Manager*>(*it)->AddSubordinate(*it2);
				}
			}
		}
	}
}

Person* Database::HireEmployee(Person *p) //hire a new employee
{
	if (!p) return NULL;
	employees.emplace_back(p);
	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); ++it)
	{
		if (typeid(**it) == typeid(Manager) && dynamic_cast<Employee*>(p)->GetDepartment() == dynamic_cast<Employee*>(*it)->GetDepartment())
			dynamic_cast<Manager*>(*it)->AddSubordinate(p);
	}
	return p;
}

bool Database::FireEmployee(int id) //fire the employee
{
	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); ++it)
	{
		if (typeid(**it) == typeid(Manager))
		{
			dynamic_cast<Manager*>(*it)->DeleteSubordinate(id);
			break;
		}
	}
	for (vector<Person*>::iterator it2 = employees.begin(); it2 != employees.end(); ++it2)
	{
		if (dynamic_cast<Employee*>(*it2)->GetId() == id)
		{
			employees.erase(it2);
			break;
		}
	}
	return true;
}

void Database::DisplayDepartmentEmployees(string _department) const
{
	cout << "~~~~~~~~~~~ Display " << _department << " Employees ~~~~~~~~~~~\n\n";
	for (vector<Person*>::const_iterator it = employees.begin(); it != employees.end(); ++it)
	{
		if (typeid(**it) == typeid(Employee))
		{
			if (dynamic_cast<Employee*>(*it)->GetDepartment() == _department)
				dynamic_cast<Employee *>(*it)->Display(true);
		}
		else
		{
			if (dynamic_cast<Manager*>(*it)->GetDepartment() == _department)
				dynamic_cast<Manager *>(*it)->Display(true);
		}
	}
}

void Database::DisplayAll() const
{
	cout << "~~~~~~~~~~~~~~~ Display all ~~~~~~~~~~~~~~~~~~~\n\n";
	for (vector<Person*>::const_iterator it = employees.begin(); it != employees.end(); ++it)
	{
		if (typeid(**it) == typeid(Employee))
		{
			dynamic_cast<Employee *>(*it)->Display(true);
		}
		else
		{
			dynamic_cast<Manager *>(*it)->Display(true);
		}
	}
}
