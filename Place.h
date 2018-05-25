/* �����: ����� �.�. 
 * ���� ��������� ������������ ������ "�����" */

#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Place
{
protected:
	string name;    // ��������
	double square;  // �������
	int population; // ���������

public:
	Place();		  // ����������� �� ���������
	Place(string _name, double _square, int _population); // ����������� � �����������
	virtual ~Place(); // ����������

	void set_name(string _name);		  // ������ ���� "��������"
	const string get_name() const;		  // ������ ���� "��������"

	void set_square(double _square);	  // ������ ���� "�������"
	double get_square() const;			  // ������ ���� "�������"

	void set_population(int _population); // ������ ���� "���������"
	int get_population() const;			  // ������ ���� "���������"

	virtual void get_CitiesNames() const {};            // ����� ������������ ������� �������� �������

	virtual ostream& display(ostream& os) = 0;			// ����� � �����
	virtual istream& input(istream& is) = 0;			// ���� � �����
	virtual ofstream& save_to_file(ofstream& of) = 0;	// ���������� � ����
	virtual ifstream& load_from_file(ifstream& in) = 0; // �������� �� �����

	friend ostream& operator << (ostream& os, Place& place); 	// ���������� ��������� ������ �� ������ �� �����
	friend istream& operator >> (istream& is, Place& place);	// ���������� ��������� ����� � �����
	friend ofstream& operator << (ofstream& of, Place& place);  // ���������� ��������� ������ �� ������ � ����
	friend ifstream& operator >> (ifstream& in, Place& place);  // ���������� ��������� ����� � ����� �� �����
};
