#include "Deque.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// конструктор за замовчуванням
Deque::Deque():Head(NULL),Tail(NULL),length(0)
{
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// деструктор
Deque::~Deque()
{
	clear();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// перевірка на порожність
bool Deque::isEmpty() const
{
	if (!length) return true;
	else return false;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// очищення колекції
void Deque::clear()
{
	while (length != 0) PopBack();
	cout << "Коллекция успешно очищена." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// додавання у початок
void Deque::PushFront(Organization *cur_data)
{
	Node *inserted;
	inserted = new Node;
	inserted->data = cur_data;
	if (isEmpty()) {
		Head = Tail = inserted;
		Head->Prev = Head->Next = NULL;
	}
	else {
		inserted->Next = Head;
		Head->Prev = inserted;
		Head = inserted;
	}
	length++;
	cout << "Объект успешно добавлен в начало." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// видалення з початку
void Deque::PopFront()
{
	if (Head) {
		Node *tmp = Head;
		if (length == 1)
		{
			Head = NULL;
			Tail = NULL;
		}
		else
		{
			Head = Head->Next;
		}
		if (tmp == Tail)
			Tail = Tail->Next;
		length--;
		delete tmp;
	}
	cout << "Объект успешно удалён с начала." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// видалення з кінця
void Deque::PopBack()
{
	if (Tail) {
		Node *tmp = Tail;
		if (length == 1)
		{
			Head = NULL;
			Tail = NULL;
		}
		else
		{
			Tail = Tail->Prev;
		}
		if (tmp == Head)
			Head = Head->Next;
		length--;
		delete tmp;
	}
	cout << "Объект успешно удалён с конца." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// збереження у файл
void Deque::saveToFile() const
{
	Node* temp = Head;
	ofstream out("Data.txt");
	if (temp) {
		out << length << endl;
		for (int i = 0; i < length - 1; i++) {
			temp->data->toFile(out);
			temp = temp->Next;
		}
		temp->data->toFile(out);
		out.close();
		cout << "Коллекция успешно сохранена в файл." << endl;
	}
	else cout << "Ошибка, коллекция пуста." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// завантаження з файлу
void Deque::loadFromFile()
{
	string type;
	clear();
	ifstream in("Data.txt");
	int n;
	if (in.is_open()) {
		in >> n;
		Organization* tmp;
		for (int i = 0; i < n;i++) {
			in >> type;
			if (type == "IndustrialEnterprise") {
				tmp = new IndustrialEnterprise;
				tmp->fromFile(in);
				PushFront(tmp);
			}
			else if (type == "InsuranceCompany") {
				tmp = new InsuranceCompany;
				tmp->fromFile(in);
				PushFront(tmp);
			}
		}
		cout << "Коллекция успешно загружена." << endl;
	}
	else  cout << "Ошибка, коллекция не найдена." << endl;
	in.close();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// вивід на екран
void Deque::print() const
{
	if (length != 0) {
		Node* temp = Head;
		for (int i = 0; i < length - 1; i++) {
			temp->data->print(cout);
			temp = temp->Next;
		}
		temp->data->print(cout);
		temp = NULL;
	}
	else cout << "Коллекция пуста." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// сортування колекції
void Deque::Sort()
{
	if (Head)
	{
		Node *tmp = NULL;
		Organization* _data;
		bool flag = true;
		while (flag)
		{
			Curr = Head;
			tmp = Curr->Next;
			flag = false;
			while (tmp != Tail->Next)
			{
				if ((Curr->data->getName()) > (tmp->data->getName()))
				{
					_data = Curr->data;
					Curr->data = tmp->data;
					tmp->data = _data;
					flag = true;
				}
				Curr = Curr->Next;
				tmp = tmp->Next;
			}
		}
		cout << "Коллекция успешно отсортирована." << endl;
	}
	else
		cout << "Коллекция пуста." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// запит до колекції
const Node* Deque::DoRequest() const
{
	if (Head)
	{
		string fund_s;
		cout << "Заданный капитал: ";
		getline(cin, fund_s);
		double fund = atof(fund_s.c_str());
		Node* temp = Head;
		cout << "Страховые компании: ";
		while (temp != Tail->Next)
		{
			temp->data->getCompanies(fund);
			temp = temp->Next;
		}
		return temp;
	}
	else
		cout << "Коллекция пуста." << endl;
	return NULL;
}