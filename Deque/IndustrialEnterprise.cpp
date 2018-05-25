#include "IndustrialEnterprise.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// конструктор за замовчуванням
IndustrialEnterprise::IndustrialEnterprise():Organization(),industry(""),size(SMALL)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// конструктор з параметрами
IndustrialEnterprise::IndustrialEnterprise(string _industry, Size _size, string name, string date_of_foundation, locate location, int num_of_workers):Organization(name, date_of_foundation, location, num_of_workers), industry(_industry), size(_size)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// деструктор 
IndustrialEnterprise::~IndustrialEnterprise()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сеттер галузі
void IndustrialEnterprise::setindustry(string _industry)
{
	industry = _industry;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сеттер розміру
void IndustrialEnterprise::setSize(Size _size)
{
	size = _size;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// геттер галузі
const string IndustrialEnterprise::getindustry() const
{
	return industry;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// геттер розміру
const Size IndustrialEnterprise::getSize() const
{
	return size;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// виведення в потік
ostream& IndustrialEnterprise::print(ostream& os) {
	os << *this;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// введення з потоку 
istream& IndustrialEnterprise::input(istream& is) {
	is >> *this;
	return is;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// виведення у файл
ofstream& IndustrialEnterprise::toFile(ofstream& of) {
	of << *this;
	return of;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// введення з файлу
ifstream & IndustrialEnterprise::fromFile(ifstream & in)
{
	in >> *this;
	return in;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// виведення у потік
ostream& operator << (ostream& os, IndustrialEnterprise& ie) {
	os << (Organization&)ie;
	os << "Отрасль: " << ie.industry << endl;
	if (ie.size == SMALL)
		os << "Размер: малое" << endl;
	else if (ie.size == MIDDLE)
		os << "Размер: среднее" << endl;
	else
		os << "Размер: большое" << endl;
	os << "\n----------------------------------------------------" << endl;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// введення з потоку 
istream& operator >> (istream& is, IndustrialEnterprise& ie) {
	is >> (Organization&)ie;
	string size_s;

	cout << "отрасль: ";
	getline(is, ie.industry);

	cout << "Размер (SMALL, MIDDLE, LARGE): ";
	getline(is, size_s);
	if (size_s == "SMALL")
		ie.size = SMALL;
	else if (size_s == "MIDDLE")
		ie.size = MIDDLE;
	else if (size_s == "LARGE")
		ie.size = LARGE;
	else
		cout << "Неправильный формат ввода. Размер будет равен SMALL." << endl;
	return is;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// виведення у файл 
ofstream& operator << (ofstream& of, IndustrialEnterprise& ie) {
	of << "IndustrialEnterprise" << endl;
	of << (Organization&)ie;
	of << ie.industry << endl;
	if (ie.size == SMALL)
		of << "SMALL" << endl;
	else if (ie.size == MIDDLE)
		of << "MIDDLE" << endl;
	else
		of << "LARGE" << endl;
	of << endl;
	return of;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// введення з файлу
ifstream& operator >> (ifstream& in, IndustrialEnterprise& ie) {
	in >> (Organization&)ie;
	in.get();
	string size_s;
	getline(in, ie.industry);
	getline(in, size_s);
	if (size_s == "SMALL")
		ie.size = SMALL;
	else if (size_s == "MIDDLE")
		ie.size = MIDDLE;
	else if (size_s == "LARGE")
		ie.size = LARGE;
	return in;
}


