#pragma once

#include <iostream>
#include "clsQueueUsingDoublyLinkedList.h"

using namespace std;

template<class T>
class clsStackUsingDoublyLinkedList : public clsQueueUsingDoublyLinkedList<T>
{
public:
	void push(T Value)
	{
		clsQueueUsingDoublyLinkedList<T>::_MyList.InsertAtBeginning(Value);
	}

	T top()
	{
		return clsQueueUsingDoublyLinkedList<T>::front();
	}

	T bottom()
	{
		return clsQueueUsingDoublyLinkedList<T>::back();
	}
};