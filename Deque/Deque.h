#pragma once
#include "InsuranceCompany.h"
#include "IndustrialEnterprise.h"
#include <fstream>

struct Node
{
	Organization *data; // інформація
	Node *Next, *Prev;  // вказівники на попередній та наступніий елементи
};

class Deque {
private:
	Node *Head; // вказівник на перший елемент дека
	Node *Tail; // вказівник на останній елемент дека
	Node *Curr; // вказівник на поточний елемент дека
	int length; // кількість елементів дека
public:
	Deque();  // конструктор за замовчуванням
	~Deque(); // деструктор

	void PushFront(Organization * cur_data); // додавання у початок
	void PopBack();          // видалення з кінця
	void PopFront();         // видалення з початку
	bool isEmpty() const;    // перевірка на порожність
	void clear();            // очищення колекції
	void print() const;      // вивід на екран
	void Sort();             // сортування колекції
	const Node* DoRequest() const; // запит до колекції

	void saveToFile() const; // збереження у файл
	void loadFromFile();     // завантаження з файлу
};

