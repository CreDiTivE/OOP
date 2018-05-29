#pragma once
#include "Railcar.h"

class TankRailcar:public Railcar
{
private:
	double volume;
public:
	TankRailcar():Railcar(), volume(0) {};
	TankRailcar(double cur_volume, double weight):Railcar(2, weight), volume(cur_volume) {};

	void set_volume(double cur_volume) { volume = cur_volume; };
	double get_volume() const { return volume; };
	void print();
	~TankRailcar() {};
};