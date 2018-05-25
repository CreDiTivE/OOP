/* Автор: Ершов А.И.
 * Файл заголовок класса выполняющего основную работу программы */

#pragma once
#include <iostream>
#include "Queue.h"

using namespace std;

class MainWork {
private:
	Queue* queue;                            // колекція
	MainWork() { queue = new Queue; };		 // конструктор по умолчанию
	~MainWork() {};							 // деструктор
	MainWork(const MainWork&) = delete;		 // конструктор копирования 
	MainWork& operator=(MainWork&) = delete; // оператор присваивания
public:
	void createRegionObject(); // добавить элемент
	void showObjects() const;  // вывести очередь на экран
	void removeObjects();	   // удалить элемент
	void saveToFile() const;   // сохранить в файл
	void loadFromFile();	   // загрузить из файла
	void sortObjects();		   // отсортировать
	void doRequest() const;    // запрос к коллекции

	void showMenu() const;	   // вывод меню на экран
	void workWithMenu();	   // работа с меню

	static MainWork& getInstance(); // статическая функция-член класса (Singleton Мэйерса)
};