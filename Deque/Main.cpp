#include "Work.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ����������� ��������
Work& initial()
{
	Work& menu = Work::Singleton();
	return menu;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������� ��������� ��������
void run(Work &menu)
{
	menu.menuDisplay();
	menu.menuWork();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ������� �������
void main()
{
	setlocale(LC_ALL, "rus");
	Work &menu = initial();
	run(menu);
	system("Pause");
}