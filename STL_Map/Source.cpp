#include "Map.h"

void main()
{
	setlocale(LC_ALL, "rus");
	Map <int, double> map(3);
	map.push(4, 2.2);
	map.push(3, 6.6);
	map.push(3, 1313.3131);
	map.push(6, 34.34);
	map.push(5, 54.54);
	cout << "Размер массива: " << map.getSize() << endl;
	cout << "Добавили элементы: " << map << endl;
	map.clear();
	cout << "Очистили массив: " << map << endl;
	map.push(7, 8.8);
	map.push(9, 7.7);
	map.push(10, 4.4);
	cout << "Добавили элементы: " << map << endl;
	cout << "Использовали индексирования: " << map[9] << endl;
	map.pop(4);
	map.pop(7);
	cout << "Удалили элемент: " << map << endl;
	Map <int, double> map2(map);
	cout << "Использовали конструктор копирования: " << map2 << endl;
	map2.changeElement(9, 5.5);
	cout << "Изменили значение элемента по ключу: " << map << endl;
	map = map2;
	cout << "Использовали операцию присваивания: " << map << endl;
	map.findElement(10);
	system("pause");
}