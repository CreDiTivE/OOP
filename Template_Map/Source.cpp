#include "Map.h"

void main()
{
	setlocale(LC_ALL, "rus");
	Map<int,double> map1(4);
	cout << "�������� �������: " << map1 << endl;
	map1.push(1, 11.1);
	map1.push(2, 12.2);
	map1.push(34, 13.3);
	map1.push(4, 14.4);
	cout << "���������� ���������: " << map1 << endl;
	cout << "�������� ��������������: " << map1[34] << endl;
	map1.push(1, 777.777);
	map1.changeElement(1, 22.22);
	cout << "������ �������� �������� �� �����: " << map1 << endl;
	Map <int, double> map2(map1);
	cout << "����������� �������: " << map2 << endl;
	map2.pop(1);
	map2.pop(2);
	cout << "�������� ��������: " << map2 << endl;
	map2.clear();
	cout << "������� �������: " << map2 << endl;
	map2 = map1;
	cout << "�������� ������������: " << map1 << endl;
	system("pause");
}
