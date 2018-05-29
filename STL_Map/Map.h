#pragma once
#include <iostream>
#include <map>
using namespace std;

template<class K, class V> class Map
{
private:
	map<K, V> myMap;
	int size;
public:

	Map(int _size) : size(_size) { ((typeid(myMap.begin()->first) == typeid(myMap.begin()->second)) ? cout << "Типы совпадают." << endl : cout << "Типы разные." << endl); }; // конструктор с параметром
	Map(const Map<K,V>& obj); // конструктор копирования
	~Map() {}; // деструктор
	void push(K _key, V _value); // добавление элемента
	void pop(K _key); // удаление элемента по ключу
	bool isEmpty() const { return myMap.empty(); }; // проверка на пустоту
	int getSize() const { return myMap.size(); }; // возврат количества элементов массива
	void clear() { return myMap.clear(); };         // очистка массива
	void findElement(K _key); // поиск элемента с заданным ключем
	void changeElement(K _key, V _value); // замена значения элемента по ключу
	const V operator [] (K _key); // перегрузка оператора индексирования
	friend ostream& operator << <>(ostream &os, const Map<K, V> &obj); // перегрузка оператора вывода
	map<K, V>& operator = (const Map<K, V> &obj); // перегрузка оператора присваивания
};

template <class K, class V> Map<K, V>::Map(const Map<K, V>& obj) // конструктор копирования
{
	if (obj.isEmpty())
		cout << "Массив пуст." << endl;
	else
	{
		size = obj.size;
		for (map<K, V>::const_iterator i = obj.myMap.begin(); i != obj.myMap.end(); i++)
			push(i->first, i->second);
	}
};

template <class K, class V> void Map<K, V>::findElement(K _key) // поиск элемента с заданным ключем
{
	if (isEmpty())
		cout << "Массив пуст." << endl;
	else
	{
		map<K, V>::iterator tmp = myMap.find(_key);
		if (tmp != myMap.end())
			cout << "Поиск элемента по ключу: " << tmp->first << " : " << tmp->second << endl;
		else
			cout << "Элемента с данным ключем нет" << endl;
	}
};

template <class K, class V> void Map<K, V>::push(K _key, V _value) // добавление элемента
{
	if (myMap.size() == size)
		cout << "Размер массива ограничен." << endl;
	else
	{
		if (myMap.find(_key) != myMap.end())
			cout << "Элемент с таким ключем уже есть." << endl;
		else
			myMap.insert(pair<K, V>(_key, _value));
	}
};

template <class K, class V> void Map<K, V>::pop(K _key) // удаление элемента по ключу
{
	if (isEmpty())
		cout << "Массив пуст." << endl;
	else
	{
		if (myMap.find(_key) != myMap.end())
			myMap.erase(_key);
		else
			cout << "Элемента с данным ключем нет" << endl;
	}
};

template <class K, class V> void Map<K, V>::changeElement(K _key, V _value) // замена значения элемента по ключу
{
	if (isEmpty())
		cout << "Массив пуст." << endl;
	else
	{
		map<K, V>::iterator tmp = myMap.find(_key);
		if (tmp != myMap.end())
			tmp->second = _value;
		else
			cout << "Элемента с данным ключем нет" << endl;
	}
};

template <class K, class V> const V Map<K, V>::operator [] (K _key) // операция индексирования
{
	if (isEmpty())
	{
		cout << "Массив пуст." << endl;
	}
	else {
		V tmp = myMap[_key];
		if(tmp)
			return tmp;
		else
			cout << "Элемента с данным ключем нет" << endl;
	}
	return NULL;
};

template <class K, class V> ostream& operator <<(ostream &os, const Map<K, V> &obj) // перегрузка оператора вывода
{
	if (obj.isEmpty())
		cout << "Массив пуст.";
	else
		for (map<K, V>::const_iterator i = obj.myMap.begin();i != obj.myMap.end();++i) os << endl << i->first << " : " << i->second;
	return os;
};

template <class K, class V> map<K, V>& Map<K, V>::operator = (const Map<K, V> &obj) // перегрузка оператора присваивания
{
	if (!(myMap.empty())) myMap.clear();
	for (map<K, V>::const_iterator i = obj.myMap.begin(); i != obj.myMap.end(); i++) push(i->first, i->second);
	return myMap;
};