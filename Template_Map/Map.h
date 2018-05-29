#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class K, class V> struct Node
{
	K key;
	V value;
};

template <class K, class V> class Map
{
private:
	Node<K, V>* getElement(K _key) const; // поиск элемента с заданным ключем
protected:
	Node<K, V> *myMap;
	int size;
	int curr_size;
public:
	Map(int _size):myMap(new Node<K,V>[_size]), size(_size), curr_size(0) { ((typeid(myMap->key) == typeid(myMap->value)) ? cout << "Типы совпадают." << endl : cout << "Типы разные." << endl); }; // конструктор с параметром
	Map(const Map<K,V>& _map);                       // конструктор копирования
	~Map() { delete[] myMap; };                      // деструктор
	bool isEmpty() const { return curr_size == 0; }; // проверка на пустоту
	int  getSize() const { return curr_size; }; // размер массива
	void push(K _key, V _value); // добавление нового элемента в массив
	void pop(K _key); // удаление элемента из массива
	void clear(); // очистка массива
	void changeElement(K _key, V _value); // изменение значения элемента за ключем
	const V operator[] (K key); // операция индексирования
	Map<K,V>* operator = (const Map<K, V>& _map); // оператор присваивания
	friend ostream& operator << <>(ostream& os, const Map<K, V>& _map); // вывод массива в поток
};

template <class K, class V> Map<K,V>::Map(const Map<K,V>& _map) // конструктор копирования
{
	size = _map.size;
	curr_size = _map.curr_size;
	myMap = new Node<K,V>[size];
	for (int i = 0; i < size; i++) {
		myMap[i] = _map.myMap[i];
	}
}

template <class K, class V> Node<K,V>* Map<K,V>::getElement(K _key) const // возврат элемента
{
	for (int i = 0; i < curr_size; i++)
	{
		if (myMap[i].key == _key)
		{
			return (myMap + i);
		}
	}
	return NULL;
}

template <class K, class V> void Map<K, V>::push(K _key, V _value) // добавление в массив
{
	if (curr_size != size) {
		if (!getElement(_key))
		{
			myMap[curr_size].value = _value;
			myMap[curr_size].key = _key;
			curr_size++;
		}
		else
			cout << "Элемент с таким ключем уже существует." << endl;
	}
	else
		cout << "Размер массива ограничен." << endl;
};

template <class K, class V> void Map<K,V>::pop(K _key) // удаление элемента
{
	if (isEmpty())
	{
		cout << "Массив пуст." << endl;
	}
	else
	{
		for (int i = 0; i < curr_size; i++)
		{
			if (myMap[i].key == _key)
			{
				for (; ++i < curr_size;)
					myMap[i - 1] = myMap[i];
				break;
			}
		}
		curr_size--;
	}
}

template <class K, class V> void Map<K, V>::clear() // очистка списка
{
	for (int i = 0; i < curr_size - 1; i++)
	{
		myMap[i] = myMap[i + 1];
	}
	curr_size = 0;
}

template <class K, class V> void Map<K,V>::changeElement(K _key, V _value) // смена значения элемента
{
	if (isEmpty())
	{
		cout << "Массив пуст." << endl;
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < curr_size; i++)
		{
			if (myMap[i].key == _key)
			{
				myMap[i].value = _value;
				flag = true;
			}
		}
		if(!flag) 
			cout << "Элемента с заданным ключем нет." << endl;
	}
		
}

template <class K, class V> const V Map<K,V>::operator [] (K _key) // операция индексирования
{
	if(isEmpty())
		cout << "Массив пуст.";
	else
	{
		for (int i = 0; i < curr_size; i++)
		{
			if (myMap[i].key == _key)
			{
				return myMap[i].value;
			}
		}
	}
	cout << "Элемента с заданным ключем нет." << endl;
	return NULL;
}

template <class K, class V> Map<K,V>* Map<K,V>::operator = (const Map<K, V> &_map) // операция присваивания
{
	if (this != &_map) // проверка на самоприсваивание
	{
		delete[] myMap;
		size = _map.size;
		curr_size = _map.curr_size;
		myMap = new Node<K,V>[size];
		for (int i = 0; i < curr_size; i++) {
			myMap[i] = _map.myMap[i];
		}
	}
	return *this;
}

template <class K, class V> ostream& operator << (ostream& os, const Map<K, V>& _map) // вывод массива в поток
{
	if (_map.isEmpty())
		os << "Массив пуст.";
	else
	{
		for (int i = 0; i < _map.curr_size; i++)
		{
			os << endl << _map.myMap[i].key << " : " << _map.myMap[i].value;
		}
	}
	return os;
};