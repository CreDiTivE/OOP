#pragma once
#include <iostream>
using namespace std;

class Railcar
{
protected:
	int type;
	double weight;
public:
	Railcar() :type(0), weight(0) {};
	Railcar(int cur_type, double cur_weight):type(cur_type), weight(cur_weight) {};

	void set_type(int cur_type) { type = cur_type; };
	int get_type() const { return type; };

	void set_weight(double cur_weight) { weight = cur_weight; };
	double get_weight() const { return weight; };

	virtual void print();
	virtual ~Railcar() {};
};