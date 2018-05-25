/* Автор: Ершов А.И.
* Реализация абстрактного класса "Город" */

#include "City.h"

//----------------------------------------------------------------------------------------------------
// Конструктор по умолчанию
City::City():Place(), transport({}), mayor("")
{
};

//----------------------------------------------------------------------------------------------------
// Конструктор инициализации с параметрами всех полей класса City
City::City(string _name, double _square, int _population, travel _transport, string _mayor):Place(_name, _square, _population),transport(_transport), mayor(_mayor)
{
};

//----------------------------------------------------------------------------------------------------
// Деструктор класса City
City::~City()
{
}

//----------------------------------------------------------------------------------------------------
// сеттер структуры "транспорт"
void City::set_transport(travel _transport)
{
	transport = _transport;
}

//----------------------------------------------------------------------------------------------------
// сеттер поля "мэр"
void City::set_mayor(string _mayor)
{
	mayor = _mayor;
}

//----------------------------------------------------------------------------------------------------
// геттер структуры "транспорт"
const travel City::get_transport() const
{
	return transport;
}

//----------------------------------------------------------------------------------------------------
// геттер поля "мэр"
const string City::get_mayor() const
{
	return mayor;
}

//----------------------------------------------------------------------------------------------------
// Вывод в поток
ostream& City::display(ostream& os)
{
	os << *this;
	return os;
}

//----------------------------------------------------------------------------------------------------
// Ввод в поток
istream& City::input(istream& is)
{
	is >> *this;
	return is;
}

//----------------------------------------------------------------------------------------------------
// Сохранение в файл
ofstream& City::save_to_file(ofstream& of)
{
	of << *this;
	return of;
}

//----------------------------------------------------------------------------------------------------
// Загрузка из файла
ifstream & City::load_from_file(ifstream & in)
{
	in >> *this;
	return in;
}

//----------------------------------------------------------------------------------------------------
// Перегрузка оператора вывода из потока на экран
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
// Перегрузка оператора ввода в поток
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
// Перегрузка оператора вывода из потока в файл
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
// Перегрузка оператора ввода в поток из файла
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

