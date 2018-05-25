/* Автор: Ершов А.И.
 * Реализация класса выполняющего основную работу программы */

#include "MainWork.h"
#include <string>

//----------------------------------------------------------------------------------------------------
// статическая функция-член класса (Singleton Мэйерса)
MainWork & MainWork::getInstance() {
	static MainWork instance;
	return instance;
}

//----------------------------------------------------------------------------------------------------
// функция выполнения программы
void MainWork::showMenu() const
{
	system("cls");
	cout << "------------Menu-------------" << endl;
	cout << "<1> Create Region object" << endl;
	cout << "<2> Show the place" << endl;
	cout << "<3> Remove the place" << endl;
	cout << "<4> Save to file" << endl;
	cout << "<5> Load from file" << endl;
	cout << "<6> Sort objects" << endl;
	cout << "<7> Do request" << endl;
	cout << "<8> Leave the program\n" << endl;
}

//----------------------------------------------------------------------------------------------------
// функция работы через меню
void MainWork::workWithMenu()
{
	int i;
	bool flag = true;
	string s;
	do {
		cout << "Main menu -> Enter number of request: ";
		getline(cin, s);
		showMenu();
		i = atoi(s.c_str());
		if (i != 0) {
			switch (i) {
			case 1: {
				cout << "Main menu -> Create Region object" << endl;
				createRegionObject();
				break;
			}
			case 2: {
				cout << "Main menu -> Show the place" << endl;
				showObjects();
				break;
			}
			case 3: {
				cout << "Main menu -> Remove the place" << endl;
				removeObjects();
				break;
			}
			case 4: {
				cout << "Main menu -> Save to file" << endl;
				saveToFile();
				break;
			}
			case 5: {
				cout << "Main menu -> Load from file" << endl;
				loadFromFile();
				break;
			}
			case 6: {
				cout << "Main menu -> Sort objects" << endl;
				sortObjects();
				break;
			}
			case 7: {
				cout << "Main menu -> Do request" << endl;
				doRequest();
				break;
			}
			case 8: {
				flag = false;
				cout << "Leaving the program..." << endl;
				break;
			}
			default: {
				cout << "Your choise is not correct..." << endl;
				break;
			}
			}
		}
		else {
			cout << "Incorrect input..." << endl;
		}
	} while (flag);
}

//----------------------------------------------------------------------------------------------------
// добавление в коллекцию
void MainWork::createRegionObject()
{
	string priority_s;
	int priority;
	while (true) {
		cout << "Input priority: ";
		getline(cin, priority_s);
		priority = atoi(priority_s.c_str());
		if (!priority)
			cout << "Incorrect input..." << endl;
		else
			break;
	}
	Region* region = new Region;
	region->input(cin);
	queue->Push(region, priority);
}

//----------------------------------------------------------------------------------------------------
// вывод коллекции на экран
void MainWork::showObjects() const
{
	queue->display();
}

//----------------------------------------------------------------------------------------------------
// удаление из коллекции
void MainWork::removeObjects()
{
	cout << "\n<1> Delete only one object" << endl;
	cout << "<2> Clear all collection" << endl;
	cout << "<3> Back to the main menu" << endl;
	int i;
	string s;
	bool flag = true;
	while (flag)
	{
		cout << "Remove Objects -> Enter number of request: ";
		getline(cin, s);
		i = atoi(s.c_str());
		if (i) {
			switch (i) {
			case 1: {
				queue->Pop();
				break;
			}
			case 2: {
				queue->clear();
				break;
			}
			case 3: {
				flag = false;
				cout << "Leaving this menu." << endl;
				break;
			}
			default: {
				cout << "Your choise is not correct..." << endl;
				break;
			}
			}
		}
		else {
			cout << "Incorrect input..." << endl;
		}
	}
	
}

//----------------------------------------------------------------------------------------------------
// сохранение в файл
void MainWork::saveToFile() const
{
	queue->saveToFile();
}

//----------------------------------------------------------------------------------------------------
// загрузка из файла
void MainWork::loadFromFile()
{
	queue->loadFromFile();
}

//----------------------------------------------------------------------------------------------------
// сортировка коллекции
void MainWork::sortObjects()
{
	queue->nameSort();
}

//----------------------------------------------------------------------------------------------------
// запрос к коллекции
void MainWork::doRequest() const
{
	string region;
	cout << "Name of the region: ";
	getline(cin, region);
	queue->request(region);
}