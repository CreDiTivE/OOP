#pragma once
#include <iostream>
#include "Deque.h"
using namespace std;

class Work {
private:
	Deque* deque; // дек з обмеженим входом
	Work();       // конструктор за замовчуванням
	~Work();      // деструктор
	Work(const Work&) = delete;      // конструктор копіювання
	Work& operator=(Work&) = delete; // оператор привласнення
public:
	static Work& Singleton();  // статична функція-член
	void menuDisplay() const;  // вивід меню на екран
	void menuWork();           // робота з меню
	void createInsurance();    // додавання страхової компанії до колекції
	void createIndustrial();   // додавання промислового підприємства до колекції
	void show() const;         // вивід на екран
	void remove();             // видалення з колекції
	void Sort();               // сортування колекції
	void Request() const;      // запит до колекції
	void save_to_file() const; // збереження у файл
	void load_from_file();     // зчитування з файла
};