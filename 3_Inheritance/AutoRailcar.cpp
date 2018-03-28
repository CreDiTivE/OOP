#include "AutoRailcar.h"
#include <iostream>
using namespace std;

AutoRailcar::AutoRailcar(int cur_numOfCars, int type, double weight):Railcar(type, weight),numOfCars(cur_numOfCars)
{
}

// Установка количества машин numOfCars
void AutoRailcar::set_numOfCars(int cur_numOfCars)
{
	numOfCars = cur_numOfCars;
}

// Получение количества машин numOfCars
int AutoRailcar::get_numOfCars() const
{
	return numOfCars;
}

void AutoRailcar::print()
{
	cout << "Количество машин: " << numOfCars << endl;
}
AutoRailcar::~AutoRailcar()
{
}