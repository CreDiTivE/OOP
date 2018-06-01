#include "Matrix3d.h"

void main()
{
	setlocale(LC_ALL, "rus");
	SparseMatrix <int> arr(4,3,2);
	arr.push(0,0,0,7);
	arr.push(2,2,1,4);
	cout << "����� ������ �� ����������� �������:\n" << arr << endl;
	cout << "���������� �����: " << arr.getRows() << endl;
	cout << "���������� ��������: " << arr.getCols() << endl;
	cout << "�������: " << arr.getDepth() << endl;
	cout << "������� � �������� ��������: " << arr(2, 2, 1) << endl;
	SparseMatrix <int> arr2(arr);
	arr2.push(1, 1, 1, 5);
	cout << "������������ �����������:\n" << arr2 << endl;
	arr = arr2;
	cout << "�������� ������������:\n" << arr << endl;
	system("pause");
}