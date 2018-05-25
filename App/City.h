/* Автор: Ершов А.И.
* Файл заголовок класса-потомка "Город" */

#pragma once
#include "Place.h"

struct travel
{
	int numOfAirports;     // количество аэропортов
	int numOfPorts;		   // количество портов
	int numOfBusStations;  // количество автобусных станций
	int numOfRailstations; // количество железнодорожных вокзалов
};

class City:public Place
{
private:
	travel transport; // транспорт
	string mayor;     // мэр города

public:
	City();  // конструктор по умолчению
	City(string _name, double _square, int _population, travel _transport, string _mayor); // конструктор с параметрами
	~City(); // деструктор

	void  set_transport(travel _transport);	 // сеттер структуры "транспорт"
	const travel get_transport() const;      // геттер структуры транспорт
	void  set_mayor(string _mayor);			 // сеттер поля "мэр"
	const string get_mayor() const;		     // геттер поля "мэр"

	ostream& display(ostream& os);			 // вывод в поток
	istream& input(istream& is);			 // ввод в поток
	ofstream& save_to_file(ofstream& of);	 // сохранение в файл
	ifstream& load_from_file(ifstream & in); // загрузка из файла

	friend ostream& operator << (ostream& os, City& city);	 // перегрузка оператора вывода из потока на экран
	friend istream& operator >> (istream& is, City& city);	 // перегрузка оператора ввода в поток
	friend ofstream& operator << (ofstream& of, City& city); // перегрузка оператора вывода из потока в файл
	friend ifstream& operator >> (ifstream& in, City& city); // перегрузка оператора ввода в поток из файла
};
