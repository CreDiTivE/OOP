#include "List.h"

void main()
{
	setlocale(LC_ALL, "rus");
	List <int> list;
	list.pushBack(3);
	list.pushBack(4);
	list.pushFront(2);
	cout << "Количество элементов: " << list.get_Size() << endl;
	cout << "Вывод с начала: " >> list << endl;
	cout << "Вывод с конца: " << list << endl;
	list.popFront();
	cout << "Удалили элемент с начала: " >> list << endl;
	list.popBack();
	cout << "Удалили элемент с конца: " >> list << endl;
	List <int> list2(list);
	cout << "Сработал конструктор копирования: " >> list2 << endl;
	list2.pushFront(10);
	list2.pushBack(15);
	list = list2;
	cout << "Операция присваивания: " >> list << endl;
	list.clear();
	cout << "Проверка на пустоту: " >> list << endl;
	system("pause");
}