#include "AutoRailcar.h"
#include <iostream>
using namespace std;

void AutoRailcar::print()
{
	Railcar::print();
	cout << "Количество машин: " << numOfCars << endl;
}