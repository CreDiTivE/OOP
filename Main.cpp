#include "AutoRailcar.h"
#include "TankRailcar.h"

void main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������� ���������� �������: ";
	cin >> n;
	Railcar** railcar = new Railcar*[n];
	int type, numOfCars;
	double weight, volume;

	for (int i = 0; i < n; i++)
	{
		cout << "�������� ��� ������:\n1 - ����� ��� ��������������� �����������\n2 - �����-��������: ";
		cin >> type;

		if (type == 1)
		{
			cout << "��� ��� �����: ";
			cin >> weight;
			cout << "������� ���������� ����: ";
			cin >> numOfCars;
			railcar[i] = new AutoRailcar(numOfCars, type, weight);
		}
		else if(type == 2)
		{
			cout << "��� ��� �����: ";
			cin >> weight;
			cout << "������� �����: ";
			cin >> volume;
			railcar[i] = new TankRailcar(volume, type, weight);
		}
		else
		{
			cout << "����� ��� ������ �� ������������." << endl;
			i--;
		}
		cout << endl;
	}

	int choose;
	cout << "������� ����� ������: ";
	cin >> choose;
	choose--;
	if (0 <= choose && choose < n)
	{
		railcar[choose]->Railcar::print();
		railcar[choose]->print();
	}
	
	for (int i = 0; i<n; i++)
		delete railcar[i];
	delete[] railcar;

	system("pause");
}