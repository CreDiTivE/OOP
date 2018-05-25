#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct locate
{
	string country;			   // країна
	string address;			   // адреса
};

class Organization
{
protected:
	string name;			   // назва
	string date_of_foundation; // дата створення
	locate location;		   // місце розташування
	int number_of_workers;	   // кількість робітників

public:
	Organization();                               // конструктор за замовчуванням
	Organization(string name, string date_of_foundation, locate location, int number_of_workers); // конструктор з параметрами
	virtual ~Organization();                      // деструктор

	void setName(string name);                    // сеттер назви
	const string getName() const;                 // геттер назви

	void setDate(string date_of_foundation);      // сеттер дати створення
	const string getDate() const;                 // геттер дати створення

	void setLocation(locate locaton);             // сеттер місця розташування
	const locate getLocation() const;             // геттер місця розташування

	void setWorkers(int number_of_workers);       // сеттер кількості робітників
	int	getWorkers() const;                       // геттер кількості робітників

	virtual void getCompanies(double _fund) const {}; // виведення найменувань страхових компаній із статутним капіталом вище заданого

	virtual ostream& print(ostream& os) = 0;      // виведення в потік
	virtual istream& input(istream& is) = 0;      // введення з потоку
	virtual ofstream& toFile(ofstream& of) = 0;   // виведення у файл
	virtual ifstream& fromFile(ifstream& in) = 0; // введення з файлу

	friend ostream& operator << (ostream& os, Organization& org);   // перевантаження оператора виведення з потоку на екран
	friend istream& operator >> (istream& is, Organization& org);   // перевантаження оператора введення в потік
	friend ofstream& operator << (ofstream& of, Organization& org); // перевантаження оператора виведення з потоку у файл
	friend ifstream& operator >> (ifstream& in, Organization& org); // перевантаження оператора введення з файлу у потік
};
