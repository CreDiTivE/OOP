#include "Work.h"
#include <string>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// статична функція-член
Work & Work::Singleton() {
	static Work instance;
	return instance;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// конструктор за замовчуванням
Work::Work() {
	deque = new Deque;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// деструктор
Work::~Work()
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// вивід меню на екран
void Work::menuDisplay() const
{
	system("cls");
	cout << "--------------------Меню--------------------" << endl;
	cout << "<1> создать объект страховой компании" << endl;
	cout << "<2> создать объект промышленного предприятия" << endl;
	cout << "<3> просмотр коллекции" << endl;
	cout << "<4> очистить коллекцию" << endl;
	cout << "<5> сохранить коллекцию в файл" << endl;
	cout << "<6> загрузить коллекцию из файла" << endl;
	cout << "<7> отсортировать коллекцию" << endl;
	cout << "<8> запрос к коллекции" << endl;
	cout << "<9> выйти из программы" << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// робота з меню
void Work::menuWork()
{
	int i;
	string s;
	do {
		cout << "\nВведите число для продолжения работы программы: ";
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
				cout << "Выход из программы." << endl;
				break;
			}
			default: {
				cout << "Нет такого пункта меню." << endl;
				break;
			}
			}
		}
		else {
			cout << "Некорректный ввод." << endl;
		}
	} while (i != 9);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// додавання страхової компанії до колекції
void Work::createInsurance()
{
	InsuranceCompany* insurance = new InsuranceCompany;
	insurance->input(cin);
	deque->PushFront(insurance);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// додавання промислового підприємства до колекції
void Work::createIndustrial()
{
	IndustrialEnterprise* industrial = new IndustrialEnterprise;
	industrial->input(cin);
	deque->PushFront(industrial);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// вивід на екран
void Work::show() const
{
	deque->print();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// видалення з колекції
void Work::remove()
{
	cout << "<1> удалить один объект с начала" << endl;
	cout << "<2> удалить один объект с конца" << endl;
	cout << "<3> очистить всю коллекцию" << endl;
	cout << "<9> выход в основное меню программы" << endl;
	int i;
	string s;
	cout << "\nВведите число для выбора варианта очистки коллекции: ";
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
			cout << "Выход в основное меню программы." << endl;
			break;
		}
		default: {
			cout << "Нет такого пункта меню." << endl;
			break;
		}
		}
	}
	else {
		cout << "Некорректный ввод." << endl;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// збереження у файл
void Work::save_to_file() const
{
	deque->saveToFile();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// зчитування з файла
void Work::load_from_file()
{
	deque->loadFromFile();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сортування колекції
void Work::Sort()
{
	deque->Sort();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// запит до колекції
void Work::Request() const
{
	deque->DoRequest();
}



