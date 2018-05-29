#include "Point.h"
#include <string>

Point newPoint()
{
	float x, y;
	cout << "������� ���������� ����� �����\nx: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	return Point(x,y);
}

void menu()
{
	cout << "* ������ � ����� ������ *" << endl
		<< "1 - ����� ��������� ����� �� �����" << endl
		<< "2 - ������� ��������� � �������� ������� ���������" << endl
		<< "3 - ������� ����� �� ���������� dx, dy" << endl
		<< "4 - ����� ��������� ����� (<<)" << endl
		<< "5 - ���� ��������� ����� (>>)" << endl
		<< "\n** ������ � ����� ������� **" << endl
		<< "11 - ����� ���� ����� (+)" << endl
		<< "12 - �������� ���� ����� (-)" << endl
		<< "13 - �������� �����" << endl
		<< "\n*** 99 - ����� �� ��������� ***" << endl;
	do {
		cout << "\n������� ����� ��� ����������� ������ ���������: ";
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
					cout << "�������� ������ �����." << endl;
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
				cout << "��� ������ ������ ����." << endl;
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
					cout << "������ �����: [" << somepoint << "] " << op[ii] << " ������ �����: [" << otherpoint << "] : " << (res ? "��" : "���") << endl;
				}
				break;
			}
			default:
			{
				cout << "��� ������ ������ ����." << endl;
			}
			}
		}
		else if (choise == 99) 
		{
			cout << "����� �� ���������." << endl;
			break;
		}
		else
			cout << "�������� ������ �����." << endl;
	} while (true);

}

void main() {
	setlocale(LC_ALL, "rus");
	menu();
	system("pause");
}