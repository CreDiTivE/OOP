/* Автор: Ершов А.И.
 * Реализация класса контейнера */

#include "Queue.h"

 //----------------------------------------------------------------------------------------------------
// конструктор по умолчанию
Queue::Queue() :Head(NULL), Tail(NULL), length(0)
{
}

//----------------------------------------------------------------------------------------------------
// деструктор
Queue::~Queue()
{
	clear();
}

//----------------------------------------------------------------------------------------------------
// проверка на пустоту
bool Queue::isEmpty() const
{
	if (!length) return true;
	else return false;
}

//----------------------------------------------------------------------------------------------------
// очистка
void Queue::clear()
{
	if (!isEmpty())
	{
		while (!isEmpty()) Pop();
		cout << "Successfully cleared." << endl;
	}
	else
		cout << "Error, collection is empty." << endl;
}

//----------------------------------------------------------------------------------------------------
// добавление элемента
void Queue::Push(Place *_data, int _priority)
{
	Node *currData = new Node;
	currData->data = _data;
	currData->priority = _priority;
	currData->Next = NULL;
	if (isEmpty())
	{
		Head = Tail = currData;
	}
	else
	{
		Tail->Next = currData;
		Tail = currData;
	}
	length++;
	prioritySort();
	cout << "Successfully pushed." << endl;
}

//----------------------------------------------------------------------------------------------------
// удаление элемента
void Queue::Pop()
{
	if (Head) {
		Node *tmp = Head;
		if (length == 1)
		{
			Head = Tail = NULL;
		}
		else
		{
			Head = Head->Next;
		}
		if (tmp == Tail)
			Tail = Tail->Next;
		length--;
		delete tmp;
		cout << "Successfully popped." << endl;
	}
	else
		cout << "Error, collection is empty." << endl;
}

//----------------------------------------------------------------------------------------------------
// сортировка по приоритету
void Queue::prioritySort()
{
	Node *tmp = NULL, *tmp2 = NULL;
	bool flag = false;
	if (Head)
	{
		do
		{
			flag = false;
			Curr = Head;
			while (Curr->Next)
			{
				if (Curr->priority > Curr->Next->priority)
				{
					if (Curr == Head)
					{
						tmp = Curr;
						Curr = tmp->Next;
						tmp->Next = Curr->Next;
						Curr->Next = tmp;
						Head = Curr;
						flag = true;
					}
					else
					{
						tmp = Curr;
						Curr = tmp->Next;
						tmp->Next = Curr->Next;
						Curr->Next = tmp;
						tmp2->Next = Curr;
						flag = true;
					}
				}
				tmp2 = Curr;
				Curr = Curr->Next;
			}
			Tail = Curr;
		} while (flag);
	}
	else
		cout << "Error, collection is empty." << endl;
}

//----------------------------------------------------------------------------------------------------
// сортировка по имени
void Queue::nameSort()
{
	Node *tmp = NULL, *tmp2 = NULL;
	bool flag = false;
	if (Head)
	{
		do
		{
			flag = false;
			Curr = Head;
			while (Curr->Next)
			{
				if (Curr->data->get_name() > Curr->Next->data->get_name())
				{
					if (Curr == Head)
					{
						tmp = Curr;
						Curr = tmp->Next;
						tmp->Next = Curr->Next;
						Curr->Next = tmp;
						Head = Curr;
						flag = true;
					}
					else
					{
						tmp = Curr;
						Curr = tmp->Next;
						tmp->Next = Curr->Next;
						Curr->Next = tmp;
						tmp2->Next = Curr;
						flag = true;
					}
				}
				tmp2 = Curr;
				Curr = Curr->Next;
			}
			Tail = Curr;
		} while (flag);
		cout << "Successfully sorted." << endl;
	}
	else
		cout << "Error, collection is empty." << endl;
}

//----------------------------------------------------------------------------------------------------
// запрос к коллекции
const Node* Queue::request(string region) const
{
	if (Head)
	{
		Node *Curr = Head;
		bool flag = true;
		while (Curr != Tail->Next)
		{
			if (Curr->data->get_name() == region)
			{
				Curr->data->get_CitiesNames();
				flag = false;
			}
			Curr = Curr->Next;
		}
		if (flag)
			cout << "Region with this name doesn`t exist." << endl;
	}
	else
		cout << "Error, collection is empty." << endl;
	return Curr;
}

//----------------------------------------------------------------------------------------------------
// сохранение в файл
void Queue::saveToFile() const
{
	Node *tmp = Head;
	ofstream out("data.txt");
	if (tmp) {
		out << length << endl;
		for (int i = 0; i < length - 1; i++) {
			out << tmp->priority << endl;
			tmp->data->save_to_file(out);
			tmp = tmp->Next;
		}
		out << tmp->priority << endl;
		tmp->data->save_to_file(out);
		out.close();
		cout << "Successfully saved." << endl;
	}
	else cout << "Error, collection is empty." << endl;
}

//----------------------------------------------------------------------------------------------------
// загрузка из файла
void Queue::loadFromFile()
{
	string type;
	clear();
	ifstream in("data.txt");
	int n, priority;
	if (in.is_open()) {
		in >> n;
		Place* tmp;
		for (int i = 0; i < n;i++) {
			in >> priority;
			in >> type;
			if (type == "Region") {
				tmp = new Region;
				tmp->load_from_file(in);
				Push(tmp, priority);
			}
			else if (type == "City") {
				tmp = new City;
				tmp->load_from_file(in);
				Push(tmp, 0);
			}
		}
		if(!isEmpty())
			cout << "Collection successfully loaded." << endl;
	}
	else  cout << "Error, collection not founded." << endl;
	in.close();
}

//----------------------------------------------------------------------------------------------------
// вывод коллекции на экран
void Queue::display() const
{
	if (length != 0) {
		Node *tmp = Head;
		for (int i = 0; i < length; i++) {
			cout << "Priority: " << tmp->priority << endl;
			tmp->data->display(cout);
			tmp = tmp->Next;
		}
	}
	else cout << "Collection is empty." << endl;
}