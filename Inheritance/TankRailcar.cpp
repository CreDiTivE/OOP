#include "TankRailcar.h"
#include <iostream>
using namespace std;

void TankRailcar::print()
{
	Railcar::print();
	cout << "�����: " << volume << endl;
}