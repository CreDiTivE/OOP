/* �����: ����� �.�.
* ���������� ������������ ������ "�������" */

#include "Region.h"

//----------------------------------------------------------------------------------------------------
// ����������� �� ���������
Region::Region():Place(), numOfCities(0), country(""), cities(new City[0]), center("")
{
};

//----------------------------------------------------------------------------------------------------
// ����������� ������������� � ����������� �����
Region::Region(string _name, double _square, int _population, int _numOfCities ,string _country, City *_cities, string _center):Place(_name, _square, _population), country(_country), numOfCities(_numOfCities), center(_center)
{
	cities = new City[_numOfCities];
	for (int i = 0; i < _numOfCities; i++) {
		cities[i] = _cities[i];
	}
};

//----------------------------------------------------------------------------------------------------
// ����������
Region::~Region()
{
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "������"
void Region::set_country(string cur_country)
{
	country = cur_country;
}

//----------------------------------------------------------------------------------------------------
// // ������ ������� �������
void Region::set_cities(City *cur_citise, int cur_numOfCities)
{
	numOfCities = cur_numOfCities;
	cities = new City[cur_numOfCities];
	for (int i = 0; i < cur_numOfCities; i++) {
		cities[i] = cur_citise[i];
	}
}

//----------------------------------------------------------------------------------------------------
//  ������ ���� "�������� �����"
void Region::set_center(string cur_center)
{
	center = cur_center;
}

//----------------------------------------------------------------------------------------------------
// ������ ���������� �������
int Region::get_numOfCities() const
{
	return numOfCities;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "������"
const string Region::get_country() const
{
	return country;
}

//----------------------------------------------------------------------------------------------------
// ������ ������� �������
const City Region::get_cities() const
{
	return *cities;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "�������� �����"
const string Region::get_center() const
{
	return center;
}

//----------------------------------------------------------------------------------------------------
// ����� � �����
ostream& Region::display(ostream& os) {
	os << *this;
	return os;
}

//----------------------------------------------------------------------------------------------------
// ���� � �����
istream& Region::input(istream& is) {
	is >> *this;
	return is;
}

//----------------------------------------------------------------------------------------------------
// ���������� � ����
ofstream& Region::save_to_file(ofstream& of) {
	of << *this;
	return of;
}

//----------------------------------------------------------------------------------------------------
// �������� �� �����
ifstream& Region::load_from_file(ifstream & in)
{
	in >> *this;
	return in;
}

//----------------------------------------------------------------------------------------------------
// ����� ���������� � �����
ostream& operator << (ostream& os, Region& region) {
	os << (Place&)region;
	os << "Country: " << region.country << endl;
	os << "Number of cities: " << region.numOfCities << endl;
	os << "Cities: " << endl;
	for (int i = 0; i < region.numOfCities; i++) {
		region.cities[i].display(cout);
	}
	os << "Regional center: " << region.center << endl;
	os << "\n<+++++++++++++++++++++++++++++++++++++++++>" << endl;
	return os;
}

//----------------------------------------------------------------------------------------------------
// ���� ���������� �� ������
istream& operator >> (istream& is, Region& region) {

	is >> (Place&)region;

	cout << "Country: ";
	getline(is, region.country);

	cout << "Number of cities: ";
	string numOfCities_s;
	getline(is, numOfCities_s);
	region.numOfCities = atoi(numOfCities_s.c_str());
	if (region.numOfCities) {
		region.cities = new City[region.numOfCities];
		for (int i = 0; i < region.numOfCities; i++) {
			region.cities[i].input(cin);
		}
	}
	else {
		cout << "Wrong input, number of cities will be zero." << endl;
		region.numOfCities = 0;
		region.cities = new City[0];
	}
	cout << "\nRegional center: ";
	getline(is, region.center);
	return is;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ������ �� ������ � ����
ofstream& operator << (ofstream& of, Region& region) {
	of << "Region" << endl;
	of << (Place&)region;
	of << region.country << endl;
	of << region.numOfCities << endl;
	for (int i = 0; i < region.numOfCities; i++) {
		of << endl;
		of << region.cities[i] << endl;
	}
	of << region.center << endl;
	of << endl;
	return of;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ����� � ����� �� �����
ifstream& operator >> (ifstream& in, Region& region) {
	in >> (Place&)region;
	in.ignore();
	getline(in, region.country);
	in >> region.numOfCities;
	
	region.cities = new City[region.numOfCities];
	for (int i = 0; i < region.numOfCities; i++) {
		in.ignore();
		in >> region.cities[i];
	}
	in >> region.center;
	return in;
}

//----------------------------------------------------------------------------------------------------
// ����� ������������ ������� �������� �������
void Region::get_CitiesNames() const
{
	cout << "Cities: ";
	for (int i = 0; i < get_numOfCities(); i++)
	{
		cout << cities[i].get_name() << " ";
	}
	cout << endl;
}