/* �����: ����� �.�.
 * ���� ��������� ������ ������������ �������� ������ ��������� */

#pragma once
#include <iostream>
#include "Queue.h"

using namespace std;

class MainWork {
private:
	Queue* queue;                            // ��������
	MainWork() { queue = new Queue; };		 // ����������� �� ���������
	~MainWork() {};							 // ����������
	MainWork(const MainWork&) = delete;		 // ����������� ����������� 
	MainWork& operator=(MainWork&) = delete; // �������� ������������
public:
	void createRegionObject(); // �������� �������
	void showObjects() const;  // ������� ������� �� �����
	void removeObjects();	   // ������� �������
	void saveToFile() const;   // ��������� � ����
	void loadFromFile();	   // ��������� �� �����
	void sortObjects();		   // �������������
	void doRequest() const;    // ������ � ���������

	void showMenu() const;	   // ����� ���� �� �����
	void workWithMenu();	   // ������ � ����

	static MainWork& getInstance(); // ����������� �������-���� ������ (Singleton �������)
};