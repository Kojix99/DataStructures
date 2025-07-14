#pragma once

#include <iostream>

#include "clsDoubleLinkedList.h"

template<class T>
class clsQueueUsingDoublyLinkedList
{
protected:
	clsDoubleLinkedList<T> _MyList;
public:
	void push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void pop()
	{
		_MyList.DeleteFirst();
	}

	T front()
	{
		if (empty()) return T();

		return _MyList.head->Value;
	}

	T back()
	{
		if (empty())return T();
		
		return _MyList.tail->Value;
	}

	bool empty()
	{
		return _MyList.IsEmpty();
	}

	int size()
	{
		return _MyList.Size();
	}

	void Clear()
	{
		_MyList.Clear();
	}
};