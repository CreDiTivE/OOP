#pragma once
#include "Organization.h"

class InsuranceCompany:public Organization
{
private:
	int rating;			  // �������
	string *countries;	  // �����
	int num_of_countries; // ������� ����
	double fund;		  // ��������� ������ ������

public:
	InsuranceCompany();   // ����������� �� �������������
	InsuranceCompany(int rating, string *countries, int num_of_countries, double fund, string name, string date_of_foundation, locate location, int num_of_workers); // ����������� � �����������
	~InsuranceCompany();  // ����������

	void setRating(int rating);         // ������ ��������
	int	getRating() const;              // ������ ��������
	void setCountries(string *countries, int num_of_countries); // ������ ����
	const string* getCountries() const; // ������ ����
	int getNumOfCountries() const;      // ������ ������� ����
	void setFund(double _fund);         // ������ ���������� ������� ������
	double getFund() const;             // ������ ���������� ������� ������
	void getCompanies(double _fund) const; // ��������� ����������� ��������� ������� �� ��������� �������� ���� ��������

	ostream& print(ostream& os);        // ��������� � ����
	istream& input(istream& is);        // �������� � ������
	ofstream& toFile(ofstream& of);     // ��������� � ����
	ifstream& fromFile(ifstream & in);  // �������� � �����

	friend ostream& operator << (ostream& os, InsuranceCompany& ic);   // �������������� ��������� ��������� � ������ �� �����
	friend istream& operator >> (istream& is, InsuranceCompany& ic);   // �������������� ��������� �������� � ����
	friend ofstream& operator << (ofstream& of, InsuranceCompany& ic); // �������������� ��������� ��������� � ������ � ����
	friend ifstream& operator >> (ifstream& in, InsuranceCompany& ic); // �������������� ��������� �������� � ����� � ����
};
