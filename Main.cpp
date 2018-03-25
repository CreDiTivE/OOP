#include "Patient.h"

#include <iostream>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "rus");
	char* name = "Александр";
	char* surname = "Ершов";
	char* lastname = "Игоревич";
	char* address = "Киев, Украина";
	int medicalCardNumber = 19;
	char* diagnosis = "Программирование 1 стадии";

	Patient obj(name, surname, lastname, address, medicalCardNumber, diagnosis);

	obj.display();
	
	char* new_name = "Тимофей";
	char* new_surname = "Алёшин";
	char* new_lastname = "Олегович";
	char* new_address = "Прага, Чехия";
	int new_medicalCardNumber = 27;
	char* new_diagnosis = "Программирование 2 стадии";

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