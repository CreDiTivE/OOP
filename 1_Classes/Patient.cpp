#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"

#include <iostream>
using namespace std;

/* Constructor with parameters Patient */

Patient::Patient(char* cur_name, char* cur_surname, char* cur_lastname, char* cur_address, int cur_medicalCardNumber, char* cur_diagnosis) :
	medicalCardNumber(cur_medicalCardNumber)
{
	name = new char[strlen(cur_name) + 1];
	strcpy(name, cur_name);

	surname = new char[strlen(cur_surname) + 1];
	strcpy(surname, cur_surname);

	lastname = new char[strlen(cur_lastname) + 1];
	strcpy(lastname, cur_lastname);

	address = new char[strlen(cur_address) + 1];
	strcpy(address, cur_address);

	diagnosis = new char[strlen(cur_diagnosis) + 1];
	strcpy(diagnosis, cur_diagnosis);
};

/* setters */
void Patient::set_name(char* cur_name)
{
	int len = strlen(cur_name);
	if (len > strlen(name))
	{
		delete[] name;
		name = new char[len + 1];
	}
	strcpy(name, cur_name);
}

void Patient::set_surname(char* cur_surname)
{
	int len = strlen(cur_surname);
	if (len > strlen(surname))
	{
		delete[] surname;
		surname = new char[len + 1];
	}
	strcpy(surname, cur_surname);
}

void Patient::set_lastname(char* cur_lastname)
{
	int len = strlen(cur_lastname);
	if (len > strlen(lastname))
	{
		delete[] lastname;
		lastname = new char[len + 1];
	}
	strcpy(lastname, cur_lastname);
}

void Patient::set_address(char* cur_address)
{
	int len = strlen(cur_address);
	if (len > strlen(address))
	{
		delete[] address;
		address = new char[len + 1];
	}
	strcpy(address, cur_address);
}

void Patient::set_medicalCardNumber(int cur_medicalCardNumber)
{
	medicalCardNumber = cur_medicalCardNumber;
}

void Patient::set_diagnosis(char* cur_diagnosis)
{
	int len = strlen(cur_diagnosis);
	if (len > strlen(diagnosis))
	{
		delete[] diagnosis;
		diagnosis = new char[len + 1];
	}
	strcpy(diagnosis, cur_diagnosis);
}

/* getters */
const char* Patient::get_name() const
{
	return name;
}
const char* Patient::get_surname() const
{
	return surname;
}
const char* Patient::get_lastname() const
{
	return lastname;
}
const char* Patient::get_address() const
{
	return address;
}
int Patient::get_medicalCardNumber() const
{
	return medicalCardNumber;
}
const char* Patient::get_diagnosis() const
{
	return diagnosis;
}

/* display method */
void Patient::display()
{
	cout << "Èìÿ: " << name << endl;
	cout << "Ôàìèëèÿ: " << surname << endl;
	cout << "Îò÷åñòâî: " << lastname << endl;
	cout << "Àäðåñ: " << address << endl;
	cout << "Íîìåð ìåä. êàðòû: " << medicalCardNumber << endl;
	cout << "Äèàãíîç: " << diagnosis << endl;
}

/* destructor */

Patient::~Patient()
{
	delete[] name;
	delete[] surname;
	delete[] lastname;
	delete[] address;
	delete[] diagnosis;
}

