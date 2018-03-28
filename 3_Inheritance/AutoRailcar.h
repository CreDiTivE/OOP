#pragma once
#include "Railcar.h"

class AutoRailcar:public Railcar
{
private:
	int numOfCars;
public:
	AutoRailcar(int, int , double);

	void set_numOfCars(int);
	int get_numOfCars() const;
	void print();
	~AutoRailcar();
};
