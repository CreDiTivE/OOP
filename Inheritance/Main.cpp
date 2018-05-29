#include "AutoRailcar.h"
#include "TankRailcar.h"

void main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество вагонов: ";
	cin >> n;
	Railcar** railcar = new Railcar*[n];
	int type, numOfCars;
	double weight, volume;

	for (int i = 0; i < n; i++)
	{
		cout << "Выберите тип вагона:\n1 - Вагон для транспортировки автомобилей\n2 - Вагон-цистерна: ";
		cin >> type;

		cout << "Вес без груза: ";
		cin >> weight;
		if (type == 1)
		{
			cout << "Введите количество авто: ";
			cin >> numOfCars;
			railcar[i] = new AutoRailcar(numOfCars, weight);
		}
		else if(type == 2)
		{
			cout << "Введите объём: ";
			cin >> volume;
			railcar[i] = new TankRailcar(volume, weight);
		}
		else
		{
			cout << "Такой тип вагона не предусмотрен." << endl;
			i--;
		}
		cout << endl;
	}

	int choose;
	while (true)
	{
		cout << "Введите номер вагона (0 для выхода из цикла): ";
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