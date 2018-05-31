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

	List():head(NULL), first(NULL), last(NULL) { }; // ����������� �� ���������
	~List() { delete[] head, first, last; };          // ����������

	void clear();        // ������� ������
	bool empty() const { return head == NULL; }; // �������� �� �������
	void push_front(const node_type val); // ���������� �������� � ������ ������
	void pop_front(); // �������� �������� � ������ ������
	int size() const;       // ������� ���������� ��������� ������
	void splice(iterator _Where, List<T>& _Right); // ������� ������� �� �������� ������ � ��������� ��� � ������ ������ ����������.
	void Print() const;     // ����� ������ �� �����

	iterator begin();  // ���������� ��������, ��������� � ������� ��������
	iterator end();                       // ���������� ��������, ��������� � ���������� ��������
	iterator find(const node_type & val); // ����� �������� � ������
	void remove(const node_type val); // ������� ������ �������, ��������������� �������. ���������� �������� �� ��������� ������� ����� ��������� ��������
	iterator remove(iterator _where);     // ������� ������� �� ��������� �������. ���������� �������� �� ��������� ������� ����� ��������� ��������
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
		cout << "������ ����." << endl;
	return;
}

template <class T> typename::List<T>::iterator List<T>::begin()   // ���������� ��������, ��������� � ������� ��������
{
	if (!first) return iterator(NULL);
	return iterator(head);
};

template <class T> typename::List<T>::iterator List<T>::end()   // ���������� ��������, ��������� � ������� ��������
{
	return iterator(NULL);
};

template <class T> typename::List<T>::iterator List<T>::find(const node_type & val) // ����� �������� � ������
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
		cout << "���������� ����� �������. ������ ����." << endl;
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
		cout << "���������� ������� �������. ������ ����." << endl;
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
		cout << "���������� ������� �������. ������ ����." << endl;
	return iterator(NULL);
};


template <class T> int List<T>::size() const // ������� ���������� ��������� ������
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

template <class T> void List<T>::push_front(const node_type val) // ���������� �������� � ������ ������
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

template <class T> void List<T>::pop_front() // �������� �������� � ������ ������
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
		cout << "���������� ������� �������. ������ ����." << endl;
	}
};

template <class T> void List<T>::clear() // ������� ������
{
	if (!empty()) {
		while (head) popBack();
	}
	else {
		cout << "������ ����." << endl;
	}
};

template <class T> void List<T>::Print() const // ����� ������ �� �����
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
		cout << "������ ����." << endl;
	}
};
