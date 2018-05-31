#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

template <typename T>
class _iterator
{
private:
	T* ptr;
public:

	typedef T value_type;
	typedef _iterator<T> it_type;
	_iterator() :ptr(0) { };
	_iterator(T* _ptr) :ptr(_ptr) { };

	T& operator *() { return *ptr; };
	void operator++() { ptr = ptr->next; };
	//dummy operator to keep compiler quiet
	void operator++(int) { ptr = ptr->next; };
	bool operator == (const it_type& _iter) const { return (ptr == _iter.ptr); };
	bool operator != (const it_type& _iter) const { return !(*this == _iter); };
	bool empty() const { return ptr == NULL; }
};
