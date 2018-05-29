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

		cout << "��� ��� �����: ";
		cin >> weight;
		if (type == 1)
		{
			cout << "������� ���������� ����: ";
			cin >> numOfCars;
			railcar[i] = new AutoRailcar(numOfCars, weight);
		}
		else if(type == 2)
		{
			cout << "������� �����: ";
			cin >> volume;
			railcar[i] = new TankRailcar(volume, weight);
		}
		else
		{
			cout << "����� ��� ������ �� ������������." << endl;
			i--;
		}
		cout << endl;
	}

	int choose;
	while (true)
	{
		cout << "������� ����� ������ (0 ��� ������ �� �����): ";
		cin >> choose;
		if (0 < choose && choose <= n)
		{
			railcar[choose-1]->print();
		}
		else if(choose == 0)
			break;
	}
	
	for (int i = 0; i<n; i++)
		delete railcar[i];
	delete[] railcar;

	system("pause");
}