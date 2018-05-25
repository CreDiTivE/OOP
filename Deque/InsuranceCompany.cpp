#include "InsuranceCompany.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� �� �������������
InsuranceCompany::InsuranceCompany():Organization(),rating(0),countries(new string[0]),fund(0)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� � �����������
InsuranceCompany::InsuranceCompany(int _rating, string *_countries, int n, double _fund, string name, string date_of_foundation, locate location, int num_of_workers):Organization(name, date_of_foundation, location, num_of_workers),rating(_rating),num_of_countries(n),fund(_fund)
{
	countries = new string[n];
	for (int i = 0; i < n; i++) {
		countries[i] = _countries[i];
	}
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� 
InsuranceCompany::~InsuranceCompany()
{
	delete[] countries;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ��������
void InsuranceCompany::setRating(int _rating)
{
	rating = _rating;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ����
void InsuranceCompany::setCountries(string *_countries, int _num_of_countries)
{
	num_of_countries = _num_of_countries;
	countries = new string[_num_of_countries];
	for (int i = 0; i < _num_of_countries; i++) {
		countries[i] = _countries[i];
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ���������� ������� ������
void InsuranceCompany::setFund(double _fund)
{
	fund = _fund;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ��������
int InsuranceCompany::getRating() const
{
	return rating;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ����
const string* InsuranceCompany::getCountries() const
{
	return countries;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ������� ����
int InsuranceCompany::getNumOfCountries() const
{
	return num_of_countries;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ���������� ������� ������
double InsuranceCompany::getFund() const
{
	return fund;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ����
ostream& InsuranceCompany::print(ostream& os) {
	os << *this;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � ������ 
istream& InsuranceCompany::input(istream& is) {
	is >> *this;
	return is;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ����
ofstream& InsuranceCompany::toFile(ofstream& of) {
	of << *this;
	return of;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � �����
ifstream & InsuranceCompany::fromFile(ifstream & in)
{
	in >> *this;
	return in;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ����
ostream& operator << (ostream& os, InsuranceCompany& ic) {
	os << (Organization&)ic;
	os << "����� � ��������: " << ic.rating << endl;
	os << "��������� �������: " << ic.fund << endl;
	os << "���������� �����: " << ic.num_of_countries << endl;
	os << "������: ";
	for (int i = 0; i < ic.num_of_countries; i++) {
		os << ic.countries[i] << " ";
	}
	os  << "\n\n----------------------------------------------------" << endl;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � ������ 
istream& operator >> (istream& is, InsuranceCompany& ic) {
	is >> (Organization&)ic;
	string rating_s, num_of_countries_s, fund_s;
	cout << "������� ��������: ";
	getline(is, rating_s);
	ic.rating = atoi(rating_s.c_str());
	if (!ic.rating)
	{
		cout << "������������ ������ �����. ������� ����� ����� ����." << endl;
		ic.rating = 0;
	}

	cout << "��������� �������: ";
	getline(is, fund_s);
	ic.fund = atof(fund_s.c_str());
	if (!ic.fund)
	{
		cout << "������������ ������ �����. ��������� ������� ����� ����." << endl;
		ic.fund = 0;
	}

	cout << "���������� �����: ";
	getline(is, num_of_countries_s);
	ic.num_of_countries = atoi(num_of_countries_s.c_str());
	if (ic.num_of_countries) {
		ic.countries = new string[ic.num_of_countries];
		for (int i = 0; i < ic.num_of_countries; i++) {
			cout << "�������� ������: ";
			getline(is, ic.countries[i]);
		}
	}
	else {
		cout << "������������ ������ �����. ���������� ����� ����� ����� ����." << endl;
		ic.num_of_countries = 0;
		ic.countries = new string[0];
	}
	return is;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ���� 
ofstream& operator << (ofstream& of, InsuranceCompany& ic) {
	of << "InsuranceCompany" << endl;
	of << (Organization&)ic;
	of << ic.rating << endl;
	of << ic.fund << endl;
	of << ic.num_of_countries << endl;
	for (int i = 0; i < ic.num_of_countries; i++) {
		of << ic.countries[i] << endl;
	}
	of << endl;
	return of;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � �����
ifstream& operator >> (ifstream& in, InsuranceCompany& ic) {
	in >> (Organization&)ic;
	in.get();
	in >> ic.rating;
	in >> ic.fund;
	in >> ic.num_of_countries;
	in.get();
	ic.countries = new string[ic.num_of_countries];
	for (int i = 0; i < ic.num_of_countries; i++) {
		getline(in, ic.countries[i]);
	}
	return in;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ����������� ��������� ������� �� ��������� �������� ���� ��������
void InsuranceCompany::getCompanies(double _fund) const
{
	if(getFund() > _fund)
	{
		cout << getName() << " ";
	}
}
