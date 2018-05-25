#include "Organization.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� �� �������������
Organization::Organization():name(""), date_of_foundation(""), location({}), number_of_workers(0)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� � �����������
Organization::Organization(string _name, string _date_of_foundation, locate _location, int _number_of_workers):name(_name), 
date_of_foundation(_date_of_foundation), location(_location), number_of_workers(_number_of_workers)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� 
Organization::~Organization()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ �����
void Organization::setName(string _name)
{
	name = _name;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ���� ���������
void Organization::setDate(string _date_of_foundation)
{
	date_of_foundation = _date_of_foundation;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ���� ������������
void Organization::setLocation(locate _location)
{
	location = _location;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ������� ��������
void Organization::setWorkers(int _number_of_workers)
{
	number_of_workers = _number_of_workers;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ �����
const string Organization::getName() const
{
	return name;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ���� ���������
const string Organization::getDate() const
{
	return date_of_foundation;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ���� ������������
const locate Organization::getLocation() const
{
	return location;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ������� ��������
int Organization::getWorkers() const
{
	return number_of_workers;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ����
ostream& operator << (ostream& os, Organization& org)
{
	os << "\n�������� �����������: " << org.name << endl;
	os << "���� ���������: " << org.date_of_foundation << endl;
	os << "������: " << org.location.country << endl;
	os << "�����: " << org.location.address << endl;
	os << "���������� �������: " << org.number_of_workers << endl;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � ������ 
istream& operator >> (istream& is, Organization& org)
{
		string cont, country, region, address, fund_s, profit_s, number_of_workers_s;
		is.get();
		cout << "�������� ��������: ";
		getline(is, org.name);
		cout << "���� �������� ��������: ";
		getline(is, org.date_of_foundation);

		cout << "����������������� ��������� ��������" << endl;
		cout << "������: ";
		getline(is, country);
		cout << "�����: ";
		getline(is, address);

		org.location = { country , address };

		cout << "���������� ����������: ";
		getline(is, number_of_workers_s);
		org.number_of_workers = atoi(number_of_workers_s.c_str());
		if (!org.number_of_workers) {
			cout << "������������ ������ �����. ���������� ���������� ����� ����� ����." << endl;
			org.number_of_workers = 0;
		}
		return is;
	}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ���� 
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
// �������� � �����
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

