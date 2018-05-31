#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

class Bus
{
public:
	template <class T> friend class List;

	Bus();
	Bus(char* _driver, char* _bus_number, char* _route_number);
	void changeName(char* _driver);
	bool loadFromCSV(char* str, List<Bus> &base);
	bool isEqual(const Bus bus);
	friend ostream& operator<<(ostream& stream, Bus &obj);
private:
	char driver[127];       // имя водителя
	char bus_number[127];   // номер автобуса
	char route_number[127]; // номер маршрутаs
};