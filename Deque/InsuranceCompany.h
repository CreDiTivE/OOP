#pragma once
#include "Organization.h"

class InsuranceCompany:public Organization
{
private:
	int rating;			  // рейтинг
	string *countries;	  // країни
	int num_of_countries; // кількість країн
	double fund;		  // статутний капітал компанії

public:
	InsuranceCompany();   // конструктор за замовчуванням
	InsuranceCompany(int rating, string *countries, int num_of_countries, double fund, string name, string date_of_foundation, locate location, int num_of_workers); // конструктор з параметрами
	~InsuranceCompany();  // деструктор

	void setRating(int rating);         // сеттер рейтингу
	int	getRating() const;              // геттер рейтингу
	void setCountries(string *countries, int num_of_countries); // сеттер країн
	const string* getCountries() const; // геттер країн
	int getNumOfCountries() const;      // геттер кількості країн
	void setFund(double _fund);         // сеттер статутного капіталу компанії
	double getFund() const;             // геттер статутного капіталу компанії
	void getCompanies(double _fund) const; // виведення найменувань страхових компаній із статутним капіталом вище заданого

	ostream& print(ostream& os);        // виведення в потік
	istream& input(istream& is);        // введення з потоку
	ofstream& toFile(ofstream& of);     // виведення у файл
	ifstream& fromFile(ifstream & in);  // введення з файлу

	friend ostream& operator << (ostream& os, InsuranceCompany& ic);   // перевантаження оператора виведення з потоку на екран
	friend istream& operator >> (istream& is, InsuranceCompany& ic);   // перевантаження оператора введення в потік
	friend ofstream& operator << (ofstream& of, InsuranceCompany& ic); // перевантаження оператора виведення з потоку у файл
	friend ifstream& operator >> (ifstream& in, InsuranceCompany& ic); // перевантаження оператора введення з файлу у потік
};
