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

	Map(int _size) : size(_size) { ((typeid(myMap.begin()->first) == typeid(myMap.begin()->second)) ? cout << "���� ���������." << endl : cout << "���� ������." << endl); }; // ����������� � ����������
	Map(const Map<K,V>& obj); // ����������� �����������
	~Map() {}; // ����������
	void push(K _key, V _value); // ���������� ��������
	void pop(K _key); // �������� �������� �� �����
	bool isEmpty() const { return myMap.empty(); }; // �������� �� �������
	int getSize() const { return myMap.size(); }; // ������� ���������� ��������� �������
	void clear() { return myMap.clear(); };         // ������� �������
	void findElement(K _key); // ����� �������� � �������� ������
	void changeElement(K _key, V _value); // ������ �������� �������� �� �����
	const V operator [] (K _key); // ���������� ��������� ��������������
	friend ostream& operator << <>(ostream &os, const Map<K, V> &obj); // ���������� ��������� ������
	map<K, V>& operator = (const Map<K, V> &obj); // ���������� ��������� ������������
};

template <class K, class V> Map<K, V>::Map(const Map<K, V>& obj) // ����������� �����������
{
	if (obj.isEmpty())
		cout << "������ ����." << endl;
	else
	{
		size = obj.size;
		for (map<K, V>::const_iterator i = obj.myMap.begin(); i != obj.myMap.end(); i++)
			push(i->first, i->second);
	}
};

template <class K, class V> void Map<K, V>::findElement(K _key) // ����� �������� � �������� ������
{
	if (isEmpty())
		cout << "������ ����." << endl;
	else
	{
		map<K, V>::iterator tmp = myMap.find(_key);
		if (tmp != myMap.end())
			cout << "����� �������� �� �����: " << tmp->first << " : " << tmp->second << endl;
		else
			cout << "�������� � ������ ������ ���" << endl;
	}
};

template <class K, class V> void Map<K, V>::push(K _key, V _value) // ���������� ��������
{
	if (myMap.size() == size)
		cout << "������ ������� ���������." << endl;
	else
	{
		if (myMap.find(_key) != myMap.end())
			cout << "������� � ����� ������ ��� ����." << endl;
		else
			myMap.insert(pair<K, V>(_key, _value));
	}
};

template <class K, class V> void Map<K, V>::pop(K _key) // �������� �������� �� �����
{
	if (isEmpty())
		cout << "������ ����." << endl;
	else
	{
		if (myMap.find(_key) != myMap.end())
			myMap.erase(_key);
		else
			cout << "�������� � ������ ������ ���" << endl;
	}
};

template <class K, class V> void Map<K, V>::changeElement(K _key, V _value) // ������ �������� �������� �� �����
{
	if (isEmpty())
		cout << "������ ����." << endl;
	else
	{
		map<K, V>::iterator tmp = myMap.find(_key);
		if (tmp != myMap.end())
			tmp->second = _value;
		else
			cout << "�������� � ������ ������ ���" << endl;
	}
};

template <class K, class V> const V Map<K, V>::operator [] (K _key) // �������� ��������������
{
	if (isEmpty())
	{
		cout << "������ ����." << endl;
	}
	else {
		V tmp = myMap[_key];
		if(tmp)
			return tmp;
		else
			cout << "�������� � ������ ������ ���" << endl;
	}
	return NULL;
};

template <class K, class V> ostream& operator <<(ostream &os, const Map<K, V> &obj) // ���������� ��������� ������
{
	if (obj.isEmpty())
		cout << "������ ����.";
	else
		for (map<K, V>::const_iterator i = obj.myMap.begin();i != obj.myMap.end();++i) os << endl << i->first << " : " << i->second;
	return os;
};

template <class K, class V> map<K, V>& Map<K, V>::operator = (const Map<K, V> &obj) // ���������� ��������� ������������
{
	if (!(myMap.empty())) myMap.clear();
	for (map<K, V>::const_iterator i = obj.myMap.begin(); i != obj.myMap.end(); i++) push(i->first, i->second);
	return myMap;
};