#pragma once
#include "Organization.h"

enum Size
{
	SMALL,
	MIDDLE,
	LARGE
};

class IndustrialEnterprise :public Organization
{
private:
	string industry; // ������
	Size size;		 // �����

public:
	IndustrialEnterprise(); // ����������� �� �������������
	IndustrialEnterprise(string industry, Size size, string name, string date_of_foundation, locate location, int num_of_workers); // ����������� � �����������
	~IndustrialEnterprise(); // ����������

	void setindustry(string industry); // ������ �����
	const string getindustry() const;  // ������ �����
	void setSize(Size size);           // ������ ������
	const Size getSize() const;        // ������ ������

	ostream& print(ostream& os);       // ��������� � ����
	istream& input(istream& is);       // �������� � ������
	ofstream& toFile(ofstream& of);    // ��������� � ���� 
	ifstream& fromFile(ifstream & in); // �������� � �����

	friend ostream& operator << (ostream& os, IndustrialEnterprise& ie);   // �������������� ��������� ��������� � ������ �� �����
	friend istream& operator >> (istream& is, IndustrialEnterprise& ie);   // �������������� ��������� �������� � ����
	friend ofstream& operator << (ofstream& of, IndustrialEnterprise& ie); // �������������� ��������� ��������� � ������ � ����
	friend ifstream& operator >> (ifstream& in, IndustrialEnterprise& ie); // �������������� ��������� �������� � ����� � ����
};
