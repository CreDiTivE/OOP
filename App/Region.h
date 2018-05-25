/* Автор: Ершов А.И.
 * Файл заголовок класса-потомка "Область" */

#pragma once
#include "Place.h"
#include "City.h"

class Region:public Place
{
private:
	int	numOfCities; // количество городов
	string country;  // страна
	string center;   // обласной центр
	City *cities;	 // массив городов

public:
	Region();  // конструктор по умолчению
	Region(string _name, double _square, int _population, int _numOfCities, string _country, City *_cities, string _center); // конструктор с параметрами
	~Region(); // деструктор

	void  set_cities(City *_cities, int _numOfCities); // сеттер массива городов
	const City get_cities() const;		// геттер массива городов
	int	 get_numOfCities() const;	    // геттер количества городов

	void get_CitiesNames() const;		// вывод наименований городов заданной области

	void set_country(string _country);  // сеттер поля "страна"
	const string get_country() const;	// геттер поля "страна"

	void  set_center(string _center);	// сеттер поля "обласной центр"
	const string get_center() const;	// геттер поля "обласной центр"

	ostream& display(ostream& os);				// вывод в поток
	istream& input(istream& is);				// ввод в поток
	ofstream& save_to_file(ofstream& of);		// сохранение в файл
	ifstream& load_from_file(ifstream & in);	// загрузка из файла

	friend ostream& operator << (ostream& os, Region& region);   // перегрузка оператора вывода из потока на экран
	friend istream& operator >> (istream& is, Region& region);   // перегрузка оператора ввода в поток
	friend ofstream& operator << (ofstream& of, Region& region); // перегрузка оператора вывода из потока в файл
	friend ifstream& operator >> (ifstream& in, Region& region); // перегрузка оператора ввода в поток из файла
};
