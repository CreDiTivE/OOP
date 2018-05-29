#include "Point.h"
#include <string>

Point newPoint()
{
	float x, y;
	cout << "Введите координаты новой точки\nx: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	return Point(x,y);
}

void menu()
{
	cout << "* Работа с одной точкой *" << endl
		<< "1 - вывод координат точки на экран" << endl
		<< "2 - перевод координат в полярную систему координат" << endl
		<< "3 - перенос точки на расстояние dx, dy" << endl
		<< "4 - вывод координат точки (<<)" << endl
		<< "5 - ввод координат точки (>>)" << endl
		<< "\n** Работа с двумя точками **" << endl
		<< "11 - Сумма двух точек (+)" << endl
		<< "12 - Разность двух точек (-)" << endl
		<< "13 - Сравнить точки" << endl
		<< "\n*** 99 - Выход из программы ***" << endl;
	do {
		cout << "\nВведите число для продолжения работы программы: ";
		string choise_s;
		cin >> choise_s;
		int choise = atoi(choise_s.c_str());
		if (0 < choise && choise < 10)
		{
			Point somepoint = newPoint();

			switch (choise)
			{
			case(1):
			{
				somepoint.display();
				break;
			}
			case(2):
			{
				somepoint.displayPolar();
				break;
			}
			case(3):
			{
				float dx, dy;
				cout << "dx: ";
				cin >> dx;
				cout << "dy: ";
				cin >> dy;
				if (dx && dy)
				{
					somepoint.transfer(dx, dy);
					somepoint.display();
				}
				else
				{
					cout << "Неверный формат ввода." << endl;
				}
				break;
			}
			case(4):
			{
				cout << somepoint;
				break;
			}
			case(5):
			{
				cin >> somepoint;
				somepoint.display();
				break;
			}
			default:
			{
				cout << "Нет такого пункта меню." << endl;
			}
			}
		}

		else if (10 < choise && choise < 99)
		{
			Point somepoint = newPoint();
			Point otherpoint = newPoint();

			switch (choise)
			{
			case(11):
			{
				auto c = somepoint + otherpoint;
				c.display();
				break;
			}
			case(12):
			{
				auto c = somepoint - otherpoint;
				c.displayPolar();
				break;
			}
			case(13):
			{
				const char* op[] = { "==", "!=", "< ", "<=", "> ", ">=" };
				for (int ii = 0; ii < 6; ii++)
				{
					bool res(ii == 0 ? somepoint == otherpoint : ii == 1 ? somepoint != otherpoint : ii == 2 ? somepoint < otherpoint : ii == 3 ? somepoint <= otherpoint : ii == 4 ? somepoint > otherpoint : somepoint >= otherpoint);
					cout << "первая точка: [" << somepoint << "] " << op[ii] << " вторая точка: [" << otherpoint << "] : " << (res ? "Да" : "Нет") << endl;
				}
				break;
			}
			default:
			{
				cout << "Нет такого пункта меню." << endl;
			}
			}
		}
		else if (choise == 99) 
		{
			cout << "Выход из программы." << endl;
			break;
		}
		else
			cout << "Неверный формат ввода." << endl;
	} while (true);

}

void main() {
	setlocale(LC_ALL, "rus");
	menu();
	system("pause");
}