#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct locate
{
	string country;			   // �����
	string address;			   // ������
};

class Organization
{
protected:
	string name;			   // �����
	string date_of_foundation; // ���� ���������
	locate location;		   // ���� ������������
	int number_of_workers;	   // ������� ��������

public:
	Organization();                               // ����������� �� �������������
	Organization(string name, string date_of_foundation, locate location, int number_of_workers); // ����������� � �����������
	virtual ~Organization();                      // ����������

	void setName(string name);                    // ������ �����
	const string getName() const;                 // ������ �����

	void setDate(string date_of_foundation);      // ������ ���� ���������
	const string getDate() const;                 // ������ ���� ���������

	void setLocation(locate locaton);             // ������ ���� ������������
	const locate getLocation() const;             // ������ ���� ������������

	void setWorkers(int number_of_workers);       // ������ ������� ��������
	int	getWorkers() const;                       // ������ ������� ��������

	virtual void getCompanies(double _fund) const {}; // ��������� ����������� ��������� ������� �� ��������� �������� ���� ��������

	virtual ostream& print(ostream& os) = 0;      // ��������� � ����
	virtual istream& input(istream& is) = 0;      // �������� � ������
	virtual ofstream& toFile(ofstream& of) = 0;   // ��������� � ����
	virtual ifstream& fromFile(ifstream& in) = 0; // �������� � �����

	friend ostream& operator << (ostream& os, Organization& org);   // �������������� ��������� ��������� � ������ �� �����
	friend istream& operator >> (istream& is, Organization& org);   // �������������� ��������� �������� � ����
	friend ofstream& operator << (ofstream& of, Organization& org); // �������������� ��������� ��������� � ������ � ����
	friend ifstream& operator >> (ifstream& in, Organization& org); // �������������� ��������� �������� � ����� � ����
};
