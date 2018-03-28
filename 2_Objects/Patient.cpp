#include "Patient.h"

Patient::Patient():name(""), surname(""), lastname(""), address(""), medicalCardNumber(0), diagnosis("")
{ 
}

/* ����������� ������������� � ����������� ���� ����� ������ Patient */

Patient::Patient(string cur_name, string cur_surname, string cur_lastname, string cur_address, int cur_medicalCardNumber, string cur_diagnosis) :
	name(cur_name), surname(cur_surname), lastname(cur_lastname), address(cur_address), diagnosis(cur_diagnosis), medicalCardNumber(cur_medicalCardNumber)
{
};

/* ������ ������������� ����� ������ */
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

/* ������ ����������� ����� ������ Patient */
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

/* ����� ���������� ��� ������ */
void Patient::display()
{
	cout << "���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "��������: " << lastname << endl;
	cout << "�����: " << address << endl;
	cout << "����� ���. �����: " << medicalCardNumber << endl;
	cout << "�������: " << diagnosis << endl;
}

/* ���������� ������ Patient */

Patient::~Patient()
{
}

