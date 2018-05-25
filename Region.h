/* �����: ����� �.�.
 * ���� ��������� ������-������� "�������" */

#pragma once
#include "Place.h"
#include "City.h"

class Region:public Place
{
private:
	int	numOfCities; // ���������� �������
	string country;  // ������
	string center;   // �������� �����
	City *cities;	 // ������ �������

public:
	Region();  // ����������� �� ���������
	Region(string _name, double _square, int _population, int _numOfCities, string _country, City *_cities, string _center); // ����������� � �����������
	~Region(); // ����������

	void  set_cities(City *_cities, int _numOfCities); // ������ ������� �������
	const City get_cities() const;		// ������ ������� �������
	int	 get_numOfCities() const;	    // ������ ���������� �������

	void get_CitiesNames() const;		// ����� ������������ ������� �������� �������

	void set_country(string _country);  // ������ ���� "������"
	const string get_country() const;	// ������ ���� "������"

	void  set_center(string _center);	// ������ ���� "�������� �����"
	const string get_center() const;	// ������ ���� "�������� �����"

	ostream& display(ostream& os);				// ����� � �����
	istream& input(istream& is);				// ���� � �����
	ofstream& save_to_file(ofstream& of);		// ���������� � ����
	ifstream& load_from_file(ifstream & in);	// �������� �� �����

	friend ostream& operator << (ostream& os, Region& region);   // ���������� ��������� ������ �� ������ �� �����
	friend istream& operator >> (istream& is, Region& region);   // ���������� ��������� ����� � �����
	friend ofstream& operator << (ofstream& of, Region& region); // ���������� ��������� ������ �� ������ � ����
	friend ifstream& operator >> (ifstream& in, Region& region); // ���������� ��������� ����� � ����� �� �����
};
