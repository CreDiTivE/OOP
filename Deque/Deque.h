#pragma once
#include "InsuranceCompany.h"
#include "IndustrialEnterprise.h"
#include <fstream>

struct Node
{
	Organization *data; // ����������
	Node *Next, *Prev;  // ��������� �� ��������� �� ��������� ��������
};

class Deque {
private:
	Node *Head; // �������� �� ������ ������� ����
	Node *Tail; // �������� �� ������� ������� ����
	Node *Curr; // �������� �� �������� ������� ����
	int length; // ������� �������� ����
public:
	Deque();  // ����������� �� �������������
	~Deque(); // ����������

	void PushFront(Organization * cur_data); // ��������� � �������
	void PopBack();          // ��������� � ����
	void PopFront();         // ��������� � �������
	bool isEmpty() const;    // �������� �� ���������
	void clear();            // �������� ��������
	void print() const;      // ���� �� �����
	void Sort();             // ���������� ��������
	const Node* DoRequest() const; // ����� �� ��������

	void saveToFile() const; // ���������� � ����
	void loadFromFile();     // ������������ � �����
};

