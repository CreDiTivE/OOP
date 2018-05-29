#include "Patient.h"

Patient::Patient():name(""), surname(""), lastname(""), address(""), medicalCardNumber(0), diagnosis("")
{ 
}

/* Конструктор инициализации с параметрами всех полей класса Patient */

Patient::Patient(string cur_name, string cur_surname, string cur_lastname, string cur_address, int cur_medicalCardNumber, string cur_diagnosis) :
	name(cur_name), surname(cur_surname), lastname(cur_lastname), address(cur_address), diagnosis(cur_diagnosis), medicalCardNumber(cur_medicalCardNumber)
{
};

/* Методы инициализации полей класса */
void Patient::set_name(string cur_name)
{
	name = cur_name;
}

void Patient::set_surname(string cur_surname)
{
	surname = cur_surname;
}

void Patient::set_lastname(string cur_lastname)
{
	lastname = cur_lastname;
}

void Patient::set_address(string cur_address)
{
	address = cur_address;
}

void Patient::set_medicalCardNumber(int cur_medicalCardNumber)
{
	medicalCardNumber = cur_medicalCardNumber;
}

void Patient::set_diagnosis(string cur_diagnosis)
{
	diagnosis = cur_diagnosis;
}

/* Методы возвращения полей класса Patient */
const string Patient::get_name() const
{
	return name;
}
const string Patient::get_surname() const
{
	return surname;
}
const string Patient::get_lastname() const
{
	return lastname;
}
const string Patient::get_address() const
{
	return address;
}
int Patient::get_medicalCardNumber() const
{
	return medicalCardNumber;
}
const string Patient::get_diagnosis() const
{
	return diagnosis;
}

/* Вывод информации про объект */
void Patient::display()
{
	cout << "Имя: " << name << endl;
	cout << "Фамилия: " << surname << endl;
	cout << "Отчество: " << lastname << endl;
	cout << "Адрес: " << address << endl;
	cout << "Номер мед. карты: " << medicalCardNumber << endl;
	cout << "Диагноз: " << diagnosis << endl;
}

/* Деструктор класса Patient */

Patient::~Patient()
{
}

