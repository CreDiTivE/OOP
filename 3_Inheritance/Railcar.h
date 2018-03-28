#pragma once
#include <iostream>
using namespace std;

class Railcar
{
protected:
	int type;
	double weight;
public:
	Railcar(int, double);

	void set_type(int);
	int get_type() const;

	void set_weight(double);
	double get_weight() const;

	virtual void print();
	virtual ~Railcar();
};