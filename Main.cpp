#include "Patient.h"

#include <iostream>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "rus");
	char* name = "���������";
	char* surname = "�����";
	char* lastname = "��������";
	char* address = "����, �������";
	int medicalCardNumber = 19;
	char* diagnosis = "���������������� 1 ������";

	Patient obj(name, surname, lastname, address, medicalCardNumber, diagnosis);

	obj.display();
	
	char* new_name = "�������";
	char* new_surname = "�����";
	char* new_lastname = "��������";
	char* new_address = "�����, �����";
	int new_medicalCardNumber = 27;
	char* new_diagnosis = "���������������� 2 ������";

	obj.set_name(new_name);
	obj.set_surname(new_surname);
	obj.set_lastname(new_lastname);
	obj.set_address(new_address);
	obj.set_medicalCardNumber(new_medicalCardNumber);
	obj.set_diagnosis(new_diagnosis);

	cout << endl;
	obj.display();
	
	system("Pause");
}