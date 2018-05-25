#include "IndustrialEnterprise.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� �� �������������
IndustrialEnterprise::IndustrialEnterprise():Organization(),industry(""),size(SMALL)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� � �����������
IndustrialEnterprise::IndustrialEnterprise(string _industry, Size _size, string name, string date_of_foundation, locate location, int num_of_workers):Organization(name, date_of_foundation, location, num_of_workers), industry(_industry), size(_size)
{
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� 
IndustrialEnterprise::~IndustrialEnterprise()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ �����
void IndustrialEnterprise::setindustry(string _industry)
{
	industry = _industry;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ������
void IndustrialEnterprise::setSize(Size _size)
{
	size = _size;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ �����
const string IndustrialEnterprise::getindustry() const
{
	return industry;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ ������
const Size IndustrialEnterprise::getSize() const
{
	return size;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ����
ostream& IndustrialEnterprise::print(ostream& os) {
	os << *this;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � ������ 
istream& IndustrialEnterprise::input(istream& is) {
	is >> *this;
	return is;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ����
ofstream& IndustrialEnterprise::toFile(ofstream& of) {
	of << *this;
	return of;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � �����
ifstream & IndustrialEnterprise::fromFile(ifstream & in)
{
	in >> *this;
	return in;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ����
ostream& operator << (ostream& os, IndustrialEnterprise& ie) {
	os << (Organization&)ie;
	os << "�������: " << ie.industry << endl;
	if (ie.size == SMALL)
		os << "������: �����" << endl;
	else if (ie.size == MIDDLE)
		os << "������: �������" << endl;
	else
		os << "������: �������" << endl;
	os << "\n----------------------------------------------------" << endl;
	return os;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� � ������ 
istream& operator >> (istream& is, IndustrialEnterprise& ie) {
	is >> (Organization&)ie;
	string size_s;

	cout << "�������: ";
	getline(is, ie.industry);

	cout << "������ (SMALL, MIDDLE, LARGE): ";
	getline(is, size_s);
	if (size_s == "SMALL")
		ie.size = SMALL;
	else if (size_s == "MIDDLE")
		ie.size = MIDDLE;
	else if (size_s == "LARGE")
		ie.size = LARGE;
	else
		cout << "������������ ������ �����. ������ ����� ����� SMALL." << endl;
	return is;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ���� 
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
// �������� � �����
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


