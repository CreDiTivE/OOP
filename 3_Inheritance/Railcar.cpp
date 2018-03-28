#include "Railcar.h"

// ����������� Railcar
Railcar::Railcar(int cur_type, double cur_weight):type(cur_type), weight(cur_weight)
{
}

// ��������� ���� type
void Railcar::set_type(int cur_type)
{
	type = cur_type;
}

// ��������� ���� type
int Railcar::get_type() const
{
	return type;
}

// ��������� ���� weight
void Railcar::set_weight(double cur_weight)
{
	weight = cur_weight;
}

// ��������� ���� weight
double Railcar::get_weight() const
{
	return weight;
}

void Railcar::print()
{
	cout << "��� ������: " << type << endl;
	cout << "��� ��� �����: " << weight << endl;
}
Railcar::~Railcar()
{
}