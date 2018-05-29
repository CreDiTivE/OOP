#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T> struct Node
{
	T data;
	Node<T> *Next;
	Node<T> *Prev;
};

template <class T> class List
{
private:
	Node<T> *Head, *Tail;
	int size;
public:
	List();
	List(const List<T>& obj);
	~List();

	bool isEmpty() const;
	const Node<T>* get_Head() const;
	const Node<T>* get_Tail() const;
	int  get_Size() const;
	void pushFront(T x);
	void pushBack(T x);
	void popFront();
	void popBack();
	void clear();
	friend ostream& operator << (ostream&os, const List<T>&list);
	friend ostream& operator >> (ostream&is, const List<T>&list);
	List<T>& operator = (const List<T> &list);
};

template <class T> List<T>::List(): Head(NULL), Tail(NULL), size(0) {} // конструктор по умолчанию


template <class T> List<T>::List(const List<T>& list) // конструктор копирования
{
	Head = NULL;
	Node<T> *Curr = list.Head;
	while (Curr)
	{
		pushBack(Curr->data);
		Curr = Curr->Next;
	}
}

template <class T> List<T>::~List() {} // деструктор

template <class T> bool List<T>::isEmpty() const // проверка на пустоту
{
	return Head == NULL;
}

template <class T> const Node<T>* List<T>::get_Head() const // возврат первого элемента списка
{
	return Head;
}

template <class T> const Node<T>* List<T>::get_Tail() const // возврат последнего элемента списка
{
	return Tail;
}

template <class T> int List<T>::get_Size() const // возврат количества элементов
{
	return size;
}

template <class T> void List<T>::pushFront(T _data) // добавление в начало списка
{
	size++;
	Node<T> *new_el = new Node<T>;
	new_el->data = _data;
	new_el->Next = new_el->Prev = NULL;

	if (isEmpty()) {
		Head = Tail = new_el;
	}
	else {
		new_el->Next = Head;
		Head->Prev = new_el;
		Head = new_el;
	}
}

template <class T> void List<T>::pushBack(T _data) // добавление в конец списка
{
	size++;
	Node<T> *new_el = new Node<T>;
	new_el->data = _data;
	new_el->Next = new_el->Prev = NULL;

	if (isEmpty()) {
		Head = Tail = new_el;
	}
	else {
		new_el->Prev = Tail;
		Tail->Next = new_el;
		Tail = new_el;
	}
}

template <class T> void List<T>::popFront() // удаление с начала списка
{
	if (Head) {
		Node<T> *tmp = Head;
		if (size == 1)
		{
			Head = Tail = NULL;
		}
		else
		{
			Head = Head->Next;
			Head->Prev = NULL;
		}
		size--;
		delete tmp;
	}
	else
		cout << "List is empty." << endl;
}

template <class T> void List<T>::popBack() // удаление с конца списка
{
	if (Tail) {
		Node<T> *tmp = Tail;
		if (size == 1)
		{
			Head = Tail = NULL;
		}
		else
		{
			Tail = Tail->Prev;
			Tail->Next = NULL;
		}
		size--;
		delete tmp;
	}
	else
		cout << "List is empty." << endl;
}

template <class T> void List<T>::clear() // очистка списка
{
	while (size != 0) popBack();
}

template <class T> ostream &operator >> (ostream &is, List<T> &list) // вывод элементов в поток начиная с начала
{
	if (list.isEmpty())
		is << "Список пуст.";
	else
	{
		const Node<T> *Curr = list.get_Head();
		while (Curr)
		{
			is << Curr->data << " ";
			Curr = Curr->Next;
		}
	}
	return is;
}

template <class T> ostream &operator << (ostream &os, List<T> &list) // вывод элементов в поток начиная с конца
{
	if (list.isEmpty())
		os << "Список пуст.";
	else
	{
		const Node<T> *Curr = list.get_Tail();
		while (Curr)
		{
			os << Curr->data << " ";
			Curr = Curr->Prev;
		}
	}
	return os;
}

template <class T> List<T>& List<T>::operator = (const List<T> &list) // операция присваивания
{
	if (this != &list) // проверка на самоприсваивание
	{
		clear();
		Node<T> *Curr = list.Head;
		while (Curr)
		{
			pushBack(Curr->data);
			Curr = Curr->Next;
		}
	}
	return List<T>(*this);
}
