/* Àâòîð: Åðøîâ À.È.
* Ðåàëèçàöèÿ àáñòðàêòíîãî êëàññà "Ãîðîä" */

#include "City.h"

//----------------------------------------------------------------------------------------------------
// Êîíñòðóêòîð ïî óìîë÷àíèþ
City::City():Place(), transport({}), mayor("")
{
};

//----------------------------------------------------------------------------------------------------
// Êîíñòðóêòîð èíèöèàëèçàöèè ñ ïàðàìåòðàìè âñåõ ïîëåé êëàññà City
City::City(string _name, double _square, int _population, travel _transport, string _mayor):Place(_name, _square, _population),transport(_transport), mayor(_mayor)
{
};

//----------------------------------------------------------------------------------------------------
// Äåñòðóêòîð êëàññà City
City::~City()
{
}

//----------------------------------------------------------------------------------------------------
// ñåòòåð ñòðóêòóðû "òðàíñïîðò"
void City::set_transport(travel _transport)
{
	transport = _transport;
}

//----------------------------------------------------------------------------------------------------
// ñåòòåð ïîëÿ "ìýð"
void City::set_mayor(string _mayor)
{
	mayor = _mayor;
}

//----------------------------------------------------------------------------------------------------
// ãåòòåð ñòðóêòóðû "òðàíñïîðò"
const travel City::get_transport() const
{
	return transport;
}

//----------------------------------------------------------------------------------------------------
// ãåòòåð ïîëÿ "ìýð"
const string City::get_mayor() const
{
	return mayor;
}

//----------------------------------------------------------------------------------------------------
// Âûâîä â ïîòîê
ostream& City::display(ostream& os)
{
	os << *this;
	return os;
}

//----------------------------------------------------------------------------------------------------
// Ââîä â ïîòîê
istream& City::input(istream& is)
{
	is >> *this;
	return is;
}

//----------------------------------------------------------------------------------------------------
// Ñîõðàíåíèå â ôàéë
ofstream& City::save_to_file(ofstream& of)
{
	of << *this;
	return of;
}

//----------------------------------------------------------------------------------------------------
// Çàãðóçêà èç ôàéëà
ifstream & City::load_from_file(ifstream & in)
{
	in >> *this;
	return in;
}

//----------------------------------------------------------------------------------------------------
// Ïåðåãðóçêà îïåðàòîðà âûâîäà èç ïîòîêà íà ýêðàí
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
// Ïåðåãðóçêà îïåðàòîðà ââîäà â ïîòîê
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
// Ïåðåãðóçêà îïåðàòîðà âûâîäà èç ïîòîêà â ôàéë
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
// Ïåðåãðóçêà îïåðàòîðà ââîäà â ïîòîê èç ôàéëà
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

