#pragma once
#include "Exception.h"

class Queue
{
private:
	int value;
	queue<int> myqueue;
public:
	bool isEmpty() const { return myqueue.empty(); };
	int  getSize() const { return myqueue.size(); };
	int getFront() { return myqueue.front(); };
	void push(int value) { myqueue.push(value); };
	void Pop() { (isEmpty() ? throw Exception("Невозможно удалить элемент так как очередь пуста.") : myqueue.pop()); };
	void print(Queue q);
};

void Queue::print(Queue q)
{
	while (q.getSize())
	{
		cout << q.getFront() << " ";
		q.Pop();
	}
	cout << endl;
}