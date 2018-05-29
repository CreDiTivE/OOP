#include "Railcar.h"

void Railcar::print()
{
	if(type == 1)
		cout << "Тип вагона - Вагон для транспортировки автомобилей." << endl;
	else
		cout << "Тип вагона - Вагон-цистерна." << endl;
	cout << "Вес без груза: " << weight << endl;
}