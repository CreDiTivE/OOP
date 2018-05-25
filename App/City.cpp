/* �����: ����� �.�.
* ���������� ������������ ������ "�����" */

#include "City.h"

//----------------------------------------------------------------------------------------------------
// ����������� �� ���������
City::City():Place(), transport({}), mayor("")
{
};

//----------------------------------------------------------------------------------------------------
// ����������� ������������� � ����������� ���� ����� ������ City
City::City(string _name, double _square, int _population, travel _transport, string _mayor):Place(_name, _square, _population),transport(_transport), mayor(_mayor)
{
};

//----------------------------------------------------------------------------------------------------
// ���������� ������ City
City::~City()
{
}

//----------------------------------------------------------------------------------------------------
// ������ ��������� "���������"
void City::set_transport(travel _transport)
{
	transport = _transport;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "���"
void City::set_mayor(string _mayor)
{
	mayor = _mayor;
}

//----------------------------------------------------------------------------------------------------
// ������ ��������� "���������"
const travel City::get_transport() const
{
	return transport;
}

//----------------------------------------------------------------------------------------------------
// ������ ���� "���"
const string City::get_mayor() const
{
	return mayor;
}

//----------------------------------------------------------------------------------------------------
// ����� � �����
ostream& City::display(ostream& os)
{
	os << *this;
	return os;
}

//----------------------------------------------------------------------------------------------------
// ���� � �����
istream& City::input(istream& is)
{
	is >> *this;
	return is;
}

//----------------------------------------------------------------------------------------------------
// ���������� � ����
ofstream& City::save_to_file(ofstream& of)
{
	of << *this;
	return of;
}

//----------------------------------------------------------------------------------------------------
// �������� �� �����
ifstream & City::load_from_file(ifstream & in)
{
	in >> *this;
	return in;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ������ �� ������ �� �����
ostream& operator << (ostream& os, City& city) 
{
	os << (Place&)city;
	os << "Number of airports: " << city.transport.numOfAirports << endl;
	os << "Number of bus stations: " << city.transport.numOfBusStations << endl;
	os << "Number of ports: " << city.transport.numOfPorts << endl;
	os << "Number of railstations: " << city.transport.numOfRailstations << endl;
	os << "Mayor: " << city.mayor << endl;
	os << endl;
	return os;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ����� � �����
istream& operator >> (istream& is, City& city) 
{
	is >> (Place&)city;
	string numOfAirports_s, numOfBusStations_s, numOfPorts_s, numOfRailstations_s;

	cout << "Number of airports: ";
	getline(is, numOfAirports_s);
	city.transport.numOfAirports = atoi(numOfAirports_s.c_str());

	cout << "Number of bus stations: ";
	getline(is, numOfBusStations_s);
	city.transport.numOfBusStations = atoi(numOfBusStations_s.c_str());
	
	cout << "Number of ports: ";
	getline(is, numOfPorts_s);
	city.transport.numOfPorts = atoi(numOfPorts_s.c_str());

	cout << "Number of railstations: ";
	getline(is, numOfRailstations_s);
	city.transport.numOfRailstations = atoi(numOfRailstations_s.c_str());

	cout << "Mayor: ";
	getline(is, city.mayor);
	return is;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ������ �� ������ � ����
ofstream& operator << (ofstream& of, City& city) {
	of << "City" << endl;
	of << (Place&)city;
	of << city.transport.numOfAirports << endl;
	of << city.transport.numOfBusStations << endl;
	of << city.transport.numOfPorts << endl;
	of << city.transport.numOfRailstations << endl;
	of << city.mayor << endl;
	return of;
}

//----------------------------------------------------------------------------------------------------
// ���������� ��������� ����� � ����� �� �����
ifstream& operator >> (ifstream& in, City& city) {
	string type;
	in >> type;
	in >> (Place&)city;
	in.ignore();
	in >> city.transport.numOfAirports;
	in >> city.transport.numOfBusStations;
	in >> city.transport.numOfPorts;
	in >> city.transport.numOfRailstations;
	in >> city.mayor;
	return in;
}

