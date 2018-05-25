/* �����: ����� �.�.
 * ���� ��������� ������ ���������� */

#pragma once
#include "City.h"
#include "Region.h"
#include <fstream>

struct Node
{
	int priority; // ���������
	Place *data;  // ����������
	Node *Next;	  // ��������� �� ��������� ������� �������
};

class Queue {
private:
	Node *Head;	  // ��������� �� ������ �������
	Node *Tail;	  // ��������� �� ��������� �������
	Node *Curr;	  // ��������� �� ������� �������
	int length;	  // ������ �������
public:
	Queue();	  // ����������� �� ���������
	~Queue();	  // ����������

	void Push(Place* _data, int _priority); // ���������� ��������
	void Pop();					// �������� ��������
	void prioritySort();		// ���������� �� ����������
	void nameSort();			// ���������� �� �����
	bool isEmpty() const;		// �������� �� �������
	void clear();				// �������� �� �������
	void display() const;		// ����� ��������� �� �����
	const Node* request(string _region) const; // ������ � ���������
	void saveToFile() const;	// ���������� � ����
	void loadFromFile();		// �������� �� �����
};
