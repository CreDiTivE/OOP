#include "Patient.h"

#include <iostream>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "rus");

	Patient obj("���������", "�����", "��������", "����, �������", 2, "���������������� 3 ������");

	obj.display();

	obj.set_name("�������");
	obj.set_surname("�����");
	obj.set_lastname("��������");
	obj.set_address("�����, �����");
	obj.set_medicalCardNumber(27);
	obj.set_diagnosis("���������������� n+1 ������");

	cout << endl;
	obj.display();
	
	system("Pause");
}