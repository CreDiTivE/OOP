#include <iostream>
#include <vector>
using namespace std;

template<class T>
class SparseMatrix
{
private:
	typedef vector < vector <vector<T>>> vector3d;
	vector3d arr;
	int rows;  // строки
	int cols;  // столбцы
	int depth; // глубина
public:
	SparseMatrix(int cur_rows, int cur_cols, int cur_depth) : rows(cur_rows), cols(cur_cols), depth(cur_depth), arr(vector<vector<vector<T>>>(cur_depth, vector<vector<T>>(cur_cols, vector<T>(cur_rows)))) { }; // конструктор с параметрами
	SparseMatrix(const SparseMatrix<T>& obj);          // конструктор копировани€
	~SparseMatrix() {};                                // деструктор

	bool isEmpty() const { return arr.empty(); };      // проверка на пустоту
	int getRows() const { return arr[0][0].size(); };  // количество строк массива
	int getCols() const { return arr[0].size(); };     // количество столбцов массива
	int getDepth() const { return arr.size(); };       // глубина массива

	void push(int x, int y, int z, T _value);          // добавление элемента
	const T operator () (int x, int y, int z);         // операци€ индексировани€
	friend ostream& operator<< <>(ostream& stream, SparseMatrix<T>& matrix); // вывод элементов в поток
	SparseMatrix<T>& operator = (const SparseMatrix<T> &obj);                // перегрузка оператора присваивани€
};

template <class T>
SparseMatrix<T>& SparseMatrix<T>::operator = (const SparseMatrix<T>& obj) // конструктор копировани€
{
	rows = obj.rows;
	cols = obj.cols;
	depth = obj.depth;
	arr = vector<vector<vector<T>>>(depth, vector<vector<T>>(cols, vector<T>(rows)));
	for (size_t i = 0; i < obj.arr.size(); i++)
	{
		for (size_t j = 0; j < obj.arr[i].size(); j++)
		{
			for (size_t k = 0; k < obj.arr[i][j].size(); k++)
			{
				arr[i][j][k] = obj.arr[i][j][k];
			}
		}
	}
	return *this;
};

template <class T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& obj) // конструктор копировани€
{
	rows = obj.rows;
	cols = obj.cols;
	depth = obj.depth;
	arr = vector<vector<vector<T>>>(depth, vector<vector<T>>(cols, vector<T>(rows)));
	for (size_t i = 0; i < obj.arr.size(); i++)
	{
		for (size_t j = 0; j < obj.arr[i].size(); j++)
		{
			for (size_t k = 0; k < obj.arr[i][j].size(); k++)
			{
				arr[i][j][k] = obj.arr[i][j][k];
			}
		}
	}
};

template <class T>
const T SparseMatrix<T>::operator ()(int x, int y, int z) // операци€ индексировани€
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = 0; j < arr[i].size(); j++)
		{
			for (size_t k = 0; k < arr[i][j].size(); k++)
			{
				if (i == z && j == y && k == x)
				{
					return arr[i][j][k];
				}
			}
		}		
	}
	return NULL;
};

template <class T>
ostream& operator<<(ostream& stream, SparseMatrix<T>& matrix) // вывод элементов в поток
{
	for (size_t i = 0; i < matrix.arr.size(); i++)
	{
		stream << endl;
		for (size_t j = 0; j < matrix.arr[i].size(); j++)
		{
			for (size_t k = 0; k < matrix.arr[i][j].size(); k++)
				stream << matrix.arr[i][j][k] << " ";
			stream << endl;
		}
	}
	return stream;
};

template <class T>
void SparseMatrix<T>::push(int x, int y, int z, T _value) // добавление элемента
{
	if (_value)
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			for (size_t j = 0; j < arr[i].size(); j++)
			{
				for (size_t k = 0; k < arr[i][j].size(); k++)
				{
					if (i == z && j == y && k == x && arr[i][j][k] == 0)
					{
						arr[i][j][k] = _value;
						return;
					}
					else if (i == z && j == y && k == x && arr[i][j][k] != 0)
					{
						cout << "“акой элемент уже существует." << endl;
						return;
					}
				}
			}
		}
		cout << "Ќеправильные координаты." << endl;
	}
	else
		cout << "Ёлемент должен быть ненулевым." << endl;
};