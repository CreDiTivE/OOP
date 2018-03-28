#pragma once
#include "Railcar.h"

class TankRailcar:public Railcar
{
private:
	double volume;
public:
	TankRailcar(double, int, double);

	void set_volume(double);
	double get_volume() const;
	void print();
	~TankRailcar();
};