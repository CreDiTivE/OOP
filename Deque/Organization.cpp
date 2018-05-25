#include "Organization.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// конструктор за замовчуванням
Organization::Organization():name(""), date_of_foundation(""), location({}), number_of_workers(0)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// конструктор з параметрами
Organization::Organization(string _name, string _date_of_foundation, locate _location, int _number_of_workers):name(_name), 
date_of_foundation(_date_of_foundation), location(_location), number_of_workers(_number_of_workers)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// деструктор 
Organization::~Organization()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сеттер назви
void Organization::setName(string _name)
{
	name = _name;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сеттер дати створення
void Organization::setDate(string _date_of_foundation)
{
	date_of_foundation = _date_of_foundation;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сеттер місця розташування
void Organization::setLocation(locate _location)
{
	location = _location;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сеттер кількості робітників
void Organization::setWorkers(int _number_of_workers)
{
	number_of_workers = _number_of_workers;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// геттер назви
const string Organization::getName() const
{
	return name;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// геттер дати створення
const string Organization::getDate() const
{
	return date_of_foundation;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// геттер місця розташування
const locate Organization::getLocation() const
{
	return location;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// геттер кількості робітників
int Organization::getWorkers() const
{
	return number_of_workers;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// виведення у потік
ostream& operator << (ostream& os, Organization& org)
{
	os << "\nНазвание организации: " << org.name << endl;
	os << "Дата основания: " << org.date_of_foundation << endl;
	os << "Страна: " << org.location.country << endl;
	os << "Адрес: " << org.location.address << endl;
	os << "Количество рабочих: " << org.number_of_workers << endl;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// введення з потоку 
istream& operator >> (istream& is, Organization& org)
{
		string cont, country, region, address, fund_s, profit_s, number_of_workers_s;
		is.get();
		cout << "название компании: ";
		getline(is, org.name);
		cout << "дата создания компании: ";
		getline(is, org.date_of_foundation);

		cout << "Месторасположение основного филлиала" << endl;
		cout << "Страна: ";
		getline(is, country);
		cout << "Адрес: ";
		getline(is, address);

		org.location = { country , address };

		cout << "Количество работников: ";
		getline(is, number_of_workers_s);
		org.number_of_workers = atoi(number_of_workers_s.c_str());
		if (!org.number_of_workers) {
			cout << "Неправильный формат ввода. Количество работников будет равно нулю." << endl;
			org.number_of_workers = 0;
		}
		return is;
	}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// виведення у файл 
ofstream& operator << (ofstream& of, Organization& org) 
{
	of << org.name << endl;
	of << org.date_of_foundation << endl;
	of << org.location.country << endl;
	of << org.location.address << endl;
	of << org.number_of_workers << endl;
	return of;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// введення з файлу
ifstream& operator >> (ifstream& in, Organization& org) 
{
	string cont, country, region, address;
	in.get();
	getline(in, org.name);
	getline(in, org.date_of_foundation);
	getline(in, country);
	getline(in, address);
	org.location = { country , address };
	in >> org.number_of_workers;
	return in;
}

