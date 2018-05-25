#pragma once
#include <iostream>
#include "Deque.h"
using namespace std;

class Work {
private:
	Deque* deque; // ��� � ��������� ������
	Work();       // ����������� �� �������������
	~Work();      // ����������
	Work(const Work&) = delete;      // ����������� ���������
	Work& operator=(Work&) = delete; // �������� ������������
public:
	static Work& Singleton();  // �������� �������-����
	void menuDisplay() const;  // ���� ���� �� �����
	void menuWork();           // ������ � ����
	void createInsurance();    // ��������� �������� ������ �� ��������
	void createIndustrial();   // ��������� ������������ ���������� �� ��������
	void show() const;         // ���� �� �����
	void remove();             // ��������� � ��������
	void Sort();               // ���������� ��������
	void Request() const;      // ����� �� ��������
	void save_to_file() const; // ���������� � ����
	void load_from_file();     // ���������� � �����
};