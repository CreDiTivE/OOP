#include "AutoRailcar.h"
#include <iostream>
using namespace std;

AutoRailcar::AutoRailcar(int cur_numOfCars, int type, double weight):Railcar(type, weight),numOfCars(cur_numOfCars)
{
}

// ��������� ���������� ����� numOfCars
void AutoRailcar::set_numOfCars(int cur_numOfCars)
{
	numOfCars = cur_numOfCars;
}

// ��������� ���������� ����� numOfCars
int AutoRailcar::get_numOfCars() const
{
	return numOfCars;
}

void AutoRailcar::print()
{
	cout << "���������� �����: " << numOfCars << endl;
}
AutoRailcar::~AutoRailcar()
{
}