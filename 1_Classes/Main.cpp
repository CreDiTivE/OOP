#include "Patient.h"

#include <iostream>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "rus");
	char* name = "Vasiliy";
	char* surname = "Pupkin";
	char* lastname = "Ivanovich";
	char* address = "Kiev, Ukraine";
	int medicalCardNumber = 19;
	char* diagnosis = "Something strange";

	Patient obj(name, surname, lastname, address, medicalCardNumber, diagnosis);

	obj.display();
	
	char* new_name = "Vasya";
	char* new_surname = "Pupkinus";
	char* new_lastname = "Petrovich";
	char* new_address = "Lviv, Ukraine";
	int new_medicalCardNumber = 27;
	char* new_diagnosis = "Something more stranger";

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
