#include "List.h"

void main()
{
	setlocale(LC_ALL, "rus");
	List <int> list;
	list.pushBack(3);
	list.pushBack(4);
	list.pushFront(2);
	cout << "���������� ���������: " << list.get_Size() << endl;
	cout << "����� � ������: " >> list << endl;
	cout << "����� � �����: " << list << endl;
	list.popFront();
	cout << "������� ������� � ������: " >> list << endl;
	list.popBack();
	cout << "������� ������� � �����: " >> list << endl;
	List <int> list2(list);
	cout << "�������� ����������� �����������: " >> list2 << endl;
	list2.pushFront(10);
	list2.pushBack(15);
	list = list2;
	cout << "�������� ������������: " >> list << endl;
	list.clear();
	cout << "�������� �� �������: " >> list << endl;
	system("pause");
}