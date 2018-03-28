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

		if (type == 1)
		{
			cout << "Вес без груза: ";
			cin >> weight;
			cout << "Введите количество авто: ";
			cin >> numOfCars;
			railcar[i] = new AutoRailcar(numOfCars, type, weight);
		}
		else if(type == 2)
		{
			cout << "Вес без груза: ";
			cin >> weight;
			cout << "Введите объём: ";
			cin >> volume;
			railcar[i] = new TankRailcar(volume, type, weight);
		}
		else
		{
			cout << "Такой тип вагона не предусмотрен." << endl;
			i--;
		}
		cout << endl;
	}

	int choose;
	cout << "Введите номер вагона: ";
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