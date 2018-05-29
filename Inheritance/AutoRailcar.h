#pragma once
#include "Railcar.h"

class AutoRailcar:public Railcar
{
private:
	int numOfCars;
public:
	AutoRailcar():Railcar(), numOfCars(0) {};
	AutoRailcar(int cur_numOfCars, double weight):Railcar(1, weight), numOfCars(cur_numOfCars) {};

	void set_numOfCars(int cur_numOfCars) { numOfCars = cur_numOfCars; };
	int get_numOfCars() const { return numOfCars; } ;
	void print();
	~AutoRailcar() {};
};
