#include "Database.h"

void main()
{
	Database data;
	try {
		data.LoadFromFile("input.csv");
	}
	catch (char* error) {
		cout << error << endl;
	}
	data.DisplayAll();
	data.ArrangeSubordinates();
	data.DisplayAll();
	Employee someone("Herbert", "Schildt", 67, 666);
	someone.SetDepartment("IT");
	someone.SetSalary(100500);
	data.HireEmployee(&someone);
	data.DisplayDepartmentEmployees("IT");
	Employee someone2(someone);
	someone2.SetId(777);
	data.FireEmployee(666);
	data.HireEmployee(&someone2);
	data.DisplayAll();
	vector<Person*> rs = data.SQL("salary", "gt", "900");
	data.ShowRecordSet(rs);
	system("pause");
};