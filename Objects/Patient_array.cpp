#include "Patient_array.h"
#include <iostream>
#include <string>
using namespace std;

Patient_array::Patient_array():numOfPatients(0), patients(new Patient*[0])
{
}

Patient_array::Patient_array(int n): numOfPatients(n)
{
	string names[] = { "���������", "����", "������", "������", "��������"};
	string surnames[] = { "���������","�������","������","������","������"};
	string lastnames[] = { "����������","����������","�������������","�������������"};
	string addresses[] = { "����","����","������","�����"};
	string diagnosis[] = { "��������","��������", "�������"};
	patients = new Patient*[n];
	for (int i = 0; i < n; i++) {
		patients[i] = new Patient(names[rand() % 5], surnames[rand() % 5], lastnames[rand() % 4], addresses[rand() % 4], i, diagnosis[rand() % 3]);
	}
}

void Patient_array::findDiagnosis(string _diagnosis)
{
	for (int i = 0; i < numOfPatients; i++)
	{
		if (_diagnosis == patients[i]->get_diagnosis())
		{
			patients[i]->display();
			cout << endl;
		}
	}
}

void Patient_array::findMedicalCardNumber(int start, int end)
{
	for (int i = 0; i < numOfPatients; i++)
	{
		int medicalCardNumber = patients[i]->get_medicalCardNumber();
		if (start < medicalCardNumber && medicalCardNumber < end)
		{
			patients[i]->display();
			cout << endl;
		}
	}
}

void Patient_array::findSurnameFirstLetter(string letter)
{
	for (int i = 0; i < numOfPatients; i++)
	{
		string name = patients[i]->get_surname();
		if (name.find(letter) == 0)
		{
			patients[i]->display();
			cout << endl;
		}
	}
}

void Patient_array::display()
{
	for (int i = 0; i < numOfPatients; i++) {
		cout << "���: " << patients[i]->get_name() << endl;
		cout << "�������: " << patients[i]->get_surname() << endl;
		cout << "��������: " << patients[i]->get_lastname() << endl;
		cout << "�����: " << patients[i]->get_address() << endl;
		cout << "����� ����������� �����: " << patients[i]->get_medicalCardNumber() << endl;
		cout << "�������: " << patients[i]->get_diagnosis() << endl;
	}
}

Patient_array::~Patient_array()
{
	for (int i = 0; i < numOfPatients; i++)
		delete patients[i];
	delete[] patients;
}
