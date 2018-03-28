#include "TankRailcar.h"
#include <iostream>
using namespace std;

TankRailcar::TankRailcar(double cur_volume, int type, double weight) :Railcar(type, weight), volume(cur_volume)
{
}

// Установка объема volume
void TankRailcar::set_volume(double cur_volume)
{
	volume = cur_volume;
}

// Получение объема volume
double TankRailcar::get_volume() const
{
	return volume;
}

void TankRailcar::print()
{
	cout << "Объём: " << volume << endl;
}
TankRailcar::~TankRailcar()
{
}