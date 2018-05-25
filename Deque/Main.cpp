#include "Work.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ініціалізація програми
Work& initial()
{
	Work& menu = Work::Singleton();
	return menu;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// функція виконання програми
void run(Work &menu)
{
	menu.menuDisplay();
	menu.menuWork();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// основна функція
void main()
{
	setlocale(LC_ALL, "rus");
	Work &menu = initial();
	run(menu);
	system("Pause");
}