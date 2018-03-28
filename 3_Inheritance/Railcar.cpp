#include "Railcar.h"

// Конструктор Railcar
Railcar::Railcar(int cur_type, double cur_weight):type(cur_type), weight(cur_weight)
{
}

// Установка типа type
void Railcar::set_type(int cur_type)
{
	type = cur_type;
}

// Получение типа type
int Railcar::get_type() const
{
	return type;
}

// Установка веса weight
void Railcar::set_weight(double cur_weight)
{
	weight = cur_weight;
}

// Получение веса weight
double Railcar::get_weight() const
{
	return weight;
}

void Railcar::print()
{
	cout << "Тип вагона: " << type << endl;
	cout << "Вес без груза: " << weight << endl;
}
Railcar::~Railcar()
{
}