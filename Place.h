/* Автор: Ершов А.И. 
 * Файл заголовок абстрактного класса "Место" */

#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Place
{
protected:
	string name;    // название
	double square;  // площадь
	int population; // население

public:
	Place();		  // конструктор по умолчению
	Place(string _name, double _square, int _population); // конструктор с параметрами
	virtual ~Place(); // деструктор

	void set_name(string _name);		  // сеттер поля "название"
	const string get_name() const;		  // геттер поля "название"

	void set_square(double _square);	  // сеттер поля "площадь"
	double get_square() const;			  // геттер поля "площадь"

	void set_population(int _population); // сеттер поля "население"
	int get_population() const;			  // геттер поля "население"

	virtual void get_CitiesNames() const {};            // вывод наименований городов заданной области

	virtual ostream& display(ostream& os) = 0;			// вывод в поток
	virtual istream& input(istream& is) = 0;			// ввод в поток
	virtual ofstream& save_to_file(ofstream& of) = 0;	// сохранение в файл
	virtual ifstream& load_from_file(ifstream& in) = 0; // загрузка из файла

	friend ostream& operator << (ostream& os, Place& place); 	// перегрузка оператора вывода из потока на экран
	friend istream& operator >> (istream& is, Place& place);	// перегрузка оператора ввода в поток
	friend ofstream& operator << (ofstream& of, Place& place);  // перегрузка оператора вывода из потока в файл
	friend ifstream& operator >> (ifstream& in, Place& place);  // перегрузка оператора ввода в поток из файла
};
