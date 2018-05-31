#pragma once
#include "Iterator.h"
#include "Bus.h"

template <class T>
class List
{
	struct ListNode
	{
		T data;
		ListNode *next;
		ListNode() :next(NULL) {};
		ListNode(T _data) :data(_data), next(NULL) {};
		void print() { cout << data; };
	};
public:
	typedef ListNode node_type;
	typedef _iterator<node_type> iterator;

	List():head(NULL), first(NULL), last(NULL) { }; // конструктор по умолчанию
	~List() { delete[] head, first, last; };          // деструктор

	void clear();        // очистка списка
	bool empty() const { return head == NULL; }; // проверка на пустоту
	void push_front(const node_type val); // добавление элемента в начало списка
	void pop_front(); // удаление элемента с начала списка
	int size() const;       // возврат количества элементов списка
	void splice(iterator _Where, List<T>& _Right); // Удаляет элемент из целевого списка и вставляет его в начало списка аргументов.
	void Print() const;     // вывод списка на экран

	iterator begin();  // возвращает итератор, обращаясь к первому элементу
	iterator end();                       // возвращает итератор, обращаясь к последнему элементу
	iterator find(const node_type & val); // поиск элемента в списке
	void remove(const node_type val); // удаляет первый элемент, соответствующий данному. Возвращает итератор на следующую позицию после удалённого элемента
	iterator remove(iterator _where);     // стирает элемент из указанной позиции. Возвращает итератор на следующую позицию после удалённого элемента
private:
	node_type *head;
	iterator *first, *last;
};

template <class T> void List<T>::splice(iterator _Where, List<T>& _Right) 
{
	if (!empty() || this == &_Right)
	{
		node_type* tmp = head;
		iterator it = begin();
		if ((*_Where).data.isEqual(head->data)) {
			_Right.push_front(tmp->data);
			remove(it);
			return;
		}

		while (!it.empty()) {
			if (it == _Where) {
				_Right.push_front(tmp->data);
				remove(it);
				return;
			}
			else {
				it++;
				tmp = tmp->next;
			}
		}
	}
	else
		cout << "Список пуст." << endl;
	return;
}

template <class T> typename::List<T>::iterator List<T>::begin()   // возвращает итератор, обращаясь к первому элементу
{
	if (!first) return iterator(NULL);
	return iterator(head);
};

template <class T> typename::List<T>::iterator List<T>::end()   // возвращает итератор, обращаясь к первому элементу
{
	return iterator(NULL);
};

template <class T> typename::List<T>::iterator List<T>::find(const node_type & val) // поиск элемента в списке
{
	if (!empty())
	{
		iterator it = begin();
		while (!it.empty()) {
			if ((*it).data.isEqual(val.data)) return it;
			++it;
		}
		return end();
	}
	else
		cout << "Невозможно найти элемент. Список пуст." << endl;
	return iterator(NULL);
};

template <class T> void List<T>::remove(const node_type val)
{
	if (!empty())
	{
		if (head->data.isEqual(val.data)) {
			pop_front();
			return;
		}
		node_type* node = head;
		node_type* tmp;
		while (node->next != NULL) {
			if (node->next->data.isEqual(val.data)) {
				tmp = node->next->next;
				delete node->next;
				node->next = tmp;
				return;
			}
			else node = node->next;
		}
	}
	else
		cout << "Невозможно удалить элемент. Список пуст." << endl;
	return;
};

template <class T> typename::List<T>::iterator List<T>::remove(iterator _where)
{
	if (!empty())
	{
		if ((*_where).data.isEqual(head->data)) {
			pop_front();
			return _where;
		}
		if (head == NULL)
			return NULL;
		node_type* node = head;
		node_type* tmp;
		iterator it = begin();
		++it;
		while (!it.empty()) {
			if ((*_where).data.isEqual(node->next->data)) {
				tmp = node->next->next;
				delete node->next;
				node->next = tmp;
				return it;
			}
			else {
				it++;
				node = node->next;
			}
		}
		return it;
	}
	else
		cout << "Невозможно удалить элемент. Список пуст." << endl;
	return iterator(NULL);
};


template <class T> int List<T>::size() const // возврат количества элементов списка
{
	int size = 0;
	if (!empty())
	{
		node_type *curr = head;
		while (curr->next != NULL) {
			size++;
			curr = curr->next;
		}
		size++;
	}
	return size;
};

template <class T> void List<T>::push_front(const node_type val) // добавление элемента в начало списка
{
	node_type *new_el = new node_type(val);

	if (empty()) {
		head = new_el;
		first = new iterator(head);
		last = new iterator(head);
	}
	else {
		new_el->next = head;
		head = new_el;
		if (first) first = NULL;
		first = new iterator(head);
	}
};

template <class T> void List<T>::pop_front() // удаление элемента с начала списка
{

	if (!empty()) {
		if (head->next == NULL)
		{
			first = NULL;
			last = NULL;
			head = NULL;
		}
		else
		{
			first++;
			head = head->next;
		}
	}
	else {
		cout << "Невозможно удалить элемент. Список пуст." << endl;
	}
};

template <class T> void List<T>::clear() // очистка списка
{
	if (!empty()) {
		while (head) popBack();
	}
	else {
		cout << "Список пуст." << endl;
	}
};

template <class T> void List<T>::Print() const // вывод списка на экран
{
	if (!empty()) {
		node_type *curr = head;
		cout << "++++++++++++++++++++++++++++++\n\n";
		while (curr != NULL) {
			cout << curr->data;
			curr = curr->next;
		}
		cout << "\n++++++++++++++++++++++++++++++\n\n";
	}
	else {
		cout << "Список пуст." << endl;
	}
};
