#include <iostream>
#include <vector>
using namespace std;

template<class T>
class SparseMatrix
{
private:
	typedef vector < vector <vector<T>>> vector3d;
	vector3d arr;
	int rows;  // ������
	int cols;  // �������
	int depth; // �������
public:
	SparseMatrix(int cur_rows, int cur_cols, int cur_depth) : rows(cur_rows), cols(cur_cols), depth(cur_depth), arr(vector<vector<vector<T>>>(cur_depth, vector<vector<T>>(cur_cols, vector<T>(cur_rows)))) { }; // ����������� � �����������
	SparseMatrix(const SparseMatrix<T>& obj);          // ����������� �����������
	~SparseMatrix() {};                                // ����������

	bool isEmpty() const { return arr.empty(); };      // �������� �� �������
	int getRows() const { return arr[0][0].size(); };  // ���������� ����� �������
	int getCols() const { return arr[0].size(); };     // ���������� �������� �������
	int getDepth() const { return arr.size(); };       // ������� �������

	void push(int x, int y, int z, T _value);          // ���������� ��������
	const T operator () (int x, int y, int z);         // �������� ��������������
	friend ostream& operator<< <>(ostream& stream, SparseMatrix<T>& matrix); // ����� ��������� � �����
	SparseMatrix<T>& operator = (const SparseMatrix<T> &obj);                // ���������� ��������� ������������
};

template <class T>
SparseMatrix<T>& SparseMatrix<T>::operator = (const SparseMatrix<T>& obj) // ����������� �����������
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
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& obj) // ����������� �����������
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
const T SparseMatrix<T>::operator ()(int x, int y, int z) // �������� ��������������
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
ostream& operator<<(ostream& stream, SparseMatrix<T>& matrix) // ����� ��������� � �����
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
void SparseMatrix<T>::push(int x, int y, int z, T _value) // ���������� ��������
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
						cout << "����� ������� ��� ����������." << endl;
						return;
					}
				}
			}
		}
		cout << "������������ ����������." << endl;
	}
	else
		cout << "������� ������ ���� ���������." << endl;
};