#include "Railcar.h"

void Railcar::print()
{
	if(type == 1)
		cout << "��� ������ - ����� ��� ��������������� �����������." << endl;
	else
		cout << "��� ������ - �����-��������." << endl;
	cout << "��� ��� �����: " << weight << endl;
}