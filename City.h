/* �����: ����� �.�.
* ���� ��������� ������-������� "�����" */

#pragma once
#include "Place.h"

struct travel
{
	int numOfAirports;     // ���������� ����������
	int numOfPorts;		   // ���������� ������
	int numOfBusStations;  // ���������� ���������� �������
	int numOfRailstations; // ���������� ��������������� ��������
};

class City:public Place
{
private:
	travel transport; // ���������
	string mayor;     // ��� ������

public:
	City();  // ����������� �� ���������
	City(string _name, double _square, int _population, travel _transport, string _mayor); // ����������� � �����������
	~City(); // ����������

	void  set_transport(travel _transport);	 // ������ ��������� "���������"
	const travel get_transport() const;      // ������ ��������� ���������
	void  set_mayor(string _mayor);			 // ������ ���� "���"
	const string get_mayor() const;		     // ������ ���� "���"

	ostream& display(ostream& os);			 // ����� � �����
	istream& input(istream& is);			 // ���� � �����
	ofstream& save_to_file(ofstream& of);	 // ���������� � ����
	ifstream& load_from_file(ifstream & in); // �������� �� �����

	friend ostream& operator << (ostream& os, City& city);	 // ���������� ��������� ������ �� ������ �� �����
	friend istream& operator >> (istream& is, City& city);	 // ���������� ��������� ����� � �����
	friend ofstream& operator << (ofstream& of, City& city); // ���������� ��������� ������ �� ������ � ����
	friend ifstream& operator >> (ifstream& in, City& city); // ���������� ��������� ����� � ����� �� �����
};
