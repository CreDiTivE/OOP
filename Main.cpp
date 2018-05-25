/* �����: ����� �.�.
 * �������� ���� ��������� */

#include "MainWork.h"

// ������� ������������� ���������
MainWork& initApp()
{
	MainWork& menu = MainWork::getInstance();
	return menu;
}

// ������� ���������� ���������
void runApp(MainWork& menu)
{
	menu.showMenu();
	menu.workWithMenu();
}

// �������� �������
void main()
{
	MainWork& menu = initApp();
	runApp(menu);
	system("Pause");
}