#include"Queue.h"

void main()
{
	setlocale(LC_ALL, "rus");
	Queue q;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	if(n)
	{
		int number;
		for (int i = 0; i < n; i++)
		{
			cout << "Введите элемент: ";
			cin >> number;
			if(number)
				q.push(number);
		}
		
		try
		{
			for (int i = 0; i <= n; i++)
			{
				q.print(q);
				q.Pop();
			}
		}
		catch (Exception& first)
		{
			cout << first.getException() << endl;
		}
		
	}
	system("pause");
}