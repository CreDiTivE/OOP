#include "Matrix3d.h"

void main()
{
	setlocale(LC_ALL, "rus");
	SparseMatrix <int> arr(4,3,2);
	arr.push(0,0,0,7);
	arr.push(2,2,1,4);
	cout << "Вывод матриц за увеличением глубины:\n" << arr << endl;
	cout << "Количество строк: " << arr.getRows() << endl;
	cout << "Количество столбцов: " << arr.getCols() << endl;
	cout << "Глубина: " << arr.getDepth() << endl;
	cout << "Элемент с заданным индексом: " << arr(2, 2, 1) << endl;
	SparseMatrix <int> arr2(arr);
	arr2.push(1, 1, 1, 5);
	cout << "Конструкктор копирования:\n" << arr2 << endl;
	arr = arr2;
	cout << "Оператор присваивания:\n" << arr << endl;
	system("pause");
}