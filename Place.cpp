/* �����: ����� �.�.
 * ���������� ������������ ������ "�����" */

#include "Place.h"

 //----------------------------------------------------------------------------------------------------
 // ����������� �� ���������
Place::Place():name(""), square(0), population(0)
{
};

//----------------------------------------------------------------------------------------------------
// ����������� ������������� � ����������� �����
Place::Place(string _name, double _square, int _population):name(_name), square(_square), population(_population)
{
};

//----------------------------------------------------------------------------------------------------
// ����������
Place::~Place()
{
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "��������"
void Place::set_name(string _name)
{
	name = _name;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "�������"
void Place::set_square(double _square)
{
	square = _square;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "���������"
void Place::set_population(int _population)
{
	population = _population;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "��������"
const string Place::get_name() const
{
	return name;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "�������"
double Place::get_square() const
{
	return square;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "���������"
int Place::get_population() const
{
	return population;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ������ �� ������ �� �����
ostream& operator << (ostream& os, Place& place)
{
	os << "\nName: " << place.name << endl;
	os << "Square: " << place.square << endl;
	os << "Population: " << place.population << endl;
	return os;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ����� � �����
istream& operator >> (istream& is, Place& place)
{
	string square_s, population_s;
	is.ignore();
	cout << "Name: ";
	getline(is, place.name);
	cout << "Square: ";
	getline(is, square_s);
	place.square = atof(square_s.c_str());
	if (!place.square) {
		cout << "Wrong input, square will be zero." << endl;
		place.square = .0;
	}
	cout << "Population: ";
	getline(is, population_s);
	place.population = atoi(population_s.c_str());
	if (!place.population) {
		cout << "Wrong input, population will be zero." << endl;
		place.population = 0;
	}
	return is;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ������ �� ������ � ����
ofstream& operator << (ofstream& of, Place& place)
{
	of << place.name << endl;
	of << place.square << endl;
	of << place.population << endl;
	return of;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ����� � ����� �� �����
ifstream& operator >> (ifstream& in, Place& place)
{
	in.ignore();
	getline(in, place.name);
	in >> place.square;
	in >> place.population;
	return in;
}