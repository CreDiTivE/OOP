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
	Node<K, V>* getElement(K _key) const; // ����� �������� � �������� ������
protected:
	Node<K, V> *myMap;
	int size;
	int curr_size;
public:
	Map(int _size):myMap(new Node<K,V>[_size]), size(_size), curr_size(0) { ((typeid(myMap->key) == typeid(myMap->value)) ? cout << "���� ���������." << endl : cout << "���� ������." << endl); }; // ����������� � ����������
	Map(const Map<K,V>& _map);                       // ����������� �����������
	~Map() { delete[] myMap; };                      // ����������
	bool isEmpty() const { return curr_size == 0; }; // �������� �� �������
	int  getSize() const { return curr_size; }; // ������ �������
	void push(K _key, V _value); // ���������� ������ �������� � ������
	void pop(K _key); // �������� �������� �� �������
	void clear(); // ������� �������
	void changeElement(K _key, V _value); // ��������� �������� �������� �� ������
	const V operator[] (K key); // �������� ��������������
	Map<K,V>* operator = (const Map<K, V>& _map); // �������� ������������
	friend ostream& operator << <>(ostream& os, const Map<K, V>& _map); // ����� ������� � �����
};

template <class K, class V> Map<K,V>::Map(const Map<K,V>& _map) // ����������� �����������
{
	size = _map.size;
	curr_size = _map.curr_size;
	myMap = new Node<K,V>[size];
	for (int i = 0; i < size; i++) {
		myMap[i] = _map.myMap[i];
	}
}

template <class K, class V> Node<K,V>* Map<K,V>::getElement(K _key) const // ������� ��������
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

template <class K, class V> void Map<K, V>::push(K _key, V _value) // ���������� � ������
{
	if (curr_size != size) {
		if (!getElement(_key))
		{
			myMap[curr_size].value = _value;
			myMap[curr_size].key = _key;
			curr_size++;
		}
		else
			cout << "������� � ����� ������ ��� ����������." << endl;
	}
	else
		cout << "������ ������� ���������." << endl;
};

template <class K, class V> void Map<K,V>::pop(K _key) // �������� ��������
{
	if (isEmpty())
	{
		cout << "������ ����." << endl;
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

template <class K, class V> void Map<K, V>::clear() // ������� ������
{
	for (int i = 0; i < curr_size - 1; i++)
	{
		myMap[i] = myMap[i + 1];
	}
	curr_size = 0;
}

template <class K, class V> void Map<K,V>::changeElement(K _key, V _value) // ����� �������� ��������
{
	if (isEmpty())
	{
		cout << "������ ����." << endl;
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
			cout << "�������� � �������� ������ ���." << endl;
	}
		
}

template <class K, class V> const V Map<K,V>::operator [] (K _key) // �������� ��������������
{
	if(isEmpty())
		cout << "������ ����.";
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
	cout << "�������� � �������� ������ ���." << endl;
	return NULL;
}

template <class K, class V> Map<K,V>* Map<K,V>::operator = (const Map<K, V> &_map) // �������� ������������
{
	if (this != &_map) // �������� �� ����������������
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

template <class K, class V> ostream& operator << (ostream& os, const Map<K, V>& _map) // ����� ������� � �����
{
	if (_map.isEmpty())
		os << "������ ����.";
	else
	{
		for (int i = 0; i < _map.curr_size; i++)
		{
			os << endl << _map.myMap[i].key << " : " << _map.myMap[i].value;
		}
	}
	return os;
};