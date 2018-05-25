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
	string industry; // галузь
	Size size;		 // розмір

public:
	IndustrialEnterprise(); // конструктор за замовчуванням
	IndustrialEnterprise(string industry, Size size, string name, string date_of_foundation, locate location, int num_of_workers); // конструктор з параметрами
	~IndustrialEnterprise(); // деструктор

	void setindustry(string industry); // сеттер галузі
	const string getindustry() const;  // геттер галузі
	void setSize(Size size);           // сеттер розміру
	const Size getSize() const;        // геттер розміру

	ostream& print(ostream& os);       // виведення в потік
	istream& input(istream& is);       // введення з потоку
	ofstream& toFile(ofstream& of);    // виведення у файл 
	ifstream& fromFile(ifstream & in); // введення з файлу

	friend ostream& operator << (ostream& os, IndustrialEnterprise& ie);   // перевантаження оператора виведення з потоку на екран
	friend istream& operator >> (istream& is, IndustrialEnterprise& ie);   // перевантаження оператора введення в потік
	friend ofstream& operator << (ofstream& of, IndustrialEnterprise& ie); // перевантаження оператора виведення з потоку у файл
	friend ifstream& operator >> (ifstream& in, IndustrialEnterprise& ie); // перевантаження оператора введення з файлу у потік
};
