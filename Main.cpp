/* Автор: Ершов А.И.
 * Основной файл программы */

#include "MainWork.h"

// функция инициализации программы
MainWork& initApp()
{
	MainWork& menu = MainWork::getInstance();
	return menu;
}

// функция выполнения программы
void runApp(MainWork& menu)
{
	menu.showMenu();
	menu.workWithMenu();
}

// основная функция
void main()
{
	MainWork& menu = initApp();
	runApp(menu);
	system("Pause");
}