#include "Work.h"
#include <string>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �������� �������-����
Work & Work::Singleton() {
	static Work instance;
	return instance;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� �� �������������
Work::Work() {
	deque = new Deque;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������
Work::~Work()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� ���� �� �����
void Work::menuDisplay() const
{
	system("cls");
	cout << "--------------------����--------------------" << endl;
	cout << "<1> ������� ������ ��������� ��������" << endl;
	cout << "<2> ������� ������ ������������� �����������" << endl;
	cout << "<3> �������� ���������" << endl;
	cout << "<4> �������� ���������" << endl;
	cout << "<5> ��������� ��������� � ����" << endl;
	cout << "<6> ��������� ��������� �� �����" << endl;
	cout << "<7> ������������� ���������" << endl;
	cout << "<8> ������ � ���������" << endl;
	cout << "<9> ����� �� ���������" << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������ � ����
void Work::menuWork()
{
	int i;
	string s;
	do {
		cout << "\n������� ����� ��� ����������� ������ ���������: ";
		getline(cin, s);
		i = atoi(s.c_str());
		if (i) {
			switch (i) {
			case 1: {
				createInsurance();
				break;
			}
			case 2: {
				createIndustrial();
				break;
			}
			case 3: {
				show();
				break;
			}
			case 4: {
				remove();
				break;
			}
			case 5: {
				save_to_file();
				break;
			}
			case 6: {
				load_from_file();
				break;
			}
			case 7: {
				Sort();
				break;
			}
			case 8: {
				Request();
				break;
			}
			case 9: {
				cout << "����� �� ���������." << endl;
				break;
			}
			default: {
				cout << "��� ������ ������ ����." << endl;
				break;
			}
			}
		}
		else {
			cout << "������������ ����." << endl;
		}
	} while (i != 9);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� �������� ������ �� ��������
void Work::createInsurance()
{
	InsuranceCompany* insurance = new InsuranceCompany;
	insurance->input(cin);
	deque->PushFront(insurance);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� ������������ ���������� �� ��������
void Work::createIndustrial()
{
	IndustrialEnterprise* industrial = new IndustrialEnterprise;
	industrial->input(cin);
	deque->PushFront(industrial);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���� �� �����
void Work::show() const
{
	deque->print();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ��������� � ��������
void Work::remove()
{
	cout << "<1> ������� ���� ������ � ������" << endl;
	cout << "<2> ������� ���� ������ � �����" << endl;
	cout << "<3> �������� ��� ���������" << endl;
	cout << "<9> ����� � �������� ���� ���������" << endl;
	int i;
	string s;
	cout << "\n������� ����� ��� ������ �������� ������� ���������: ";
	getline(cin, s);
	i = atoi(s.c_str());
	if (i) {
		switch (i) {
		case 1: {
			deque->PopFront();
			break;
		}
		case 2: {
			deque->PopBack();
			break;
		}
		case 3: {
			deque->clear();
			break;
		}
		case 9: {
			cout << "����� � �������� ���� ���������." << endl;
			break;
		}
		default: {
			cout << "��� ������ ������ ����." << endl;
			break;
		}
		}
	}
	else {
		cout << "������������ ����." << endl;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� � ����
void Work::save_to_file() const
{
	deque->saveToFile();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� � �����
void Work::load_from_file()
{
	deque->loadFromFile();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ���������� ��������
void Work::Sort()
{
	deque->Sort();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����� �� ��������
void Work::Request() const
{
	deque->DoRequest();
}



