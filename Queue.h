/* Автор: Ершов А.И.
 * Файл заголовок класса контейнера */

#pragma once
#include "City.h"
#include "Region.h"
#include <fstream>

struct Node
{
	int priority; // приоритет
	Place *data;  // информация
	Node *Next;	  // указатель на следующий элемент очереди
};

class Queue {
private:
	Node *Head;	  // указатель на первый элемент
	Node *Tail;	  // указатель на последний элемент
	Node *Curr;	  // указатель на текущий элемент
	int length;	  // размер очереди
public:
	Queue();	  // конструктор по умолчанию
	~Queue();	  // деструктор

	void Push(Place* _data, int _priority); // добавление элемента
	void Pop();					// удаление элемента
	void prioritySort();		// сортировка по приоритету
	void nameSort();			// сортировка по имени
	bool isEmpty() const;		// проверка на пустоту
	void clear();				// проверка на пустоту
	void display() const;		// вывод коллекции на экран
	const Node* request(string _region) const; // запрос к коллекции
	void saveToFile() const;	// сохранение в файл
	void loadFromFile();		// загрузка из файла
};
