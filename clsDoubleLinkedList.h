#pragma once

#include <iostream>

using namespace std;

template <class T>

class clsDoubleLinkedList
{
private:
	class Node
	{
	public:
		T Value;
		Node* next;
		Node* prev;
	};

public:
	Node* head = nullptr;
	Node* tail = nullptr;
	int _Size = 0;

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->prev = nullptr;
		NewNode->next = head;

		if (head != nullptr)
			head->prev = NewNode;
		else
			tail = NewNode;

		head = NewNode;
		_Size++;
	}

	void InsertAtEnd(T Value)
	{
		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->next = nullptr;

		if (head == nullptr)
		{
			NewNode->prev = nullptr;
			head = NewNode;
			tail = NewNode;
			_Size++;
			return;
		}

		tail->next = NewNode;
		NewNode->prev = tail;
		tail = NewNode;
		_Size++;
	}

	Node* Find(T Value)
	{
		Node* Current = head;

		while (Current != nullptr)
		{
			if (Current->Value == Value)
			{
				return Current;
			}
			Current = Current->next;
		}
		return nullptr;
	}

	Node* GetNode(int index)
	{
		if (index < 0 || index >= _Size) return nullptr;

		Node* Current = head;
		int Counter = 0;
		while (Current != nullptr)
		{
			if (Counter == index)
				return Current;
			Current = Current->next;
			Counter++;
		}
		return nullptr;
	}

	void InsertBefore(int index, T Value)
	{
		if (index == 0)
		{
			InsertAtBeginning(Value);
			return;
		}
		
		Node* Current = GetNode(index);
		if (Current == nullptr) return;

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->prev = Current->prev;
		NewNode->next = Current;

		Current->prev->next = NewNode;
		Current->prev = NewNode;
		_Size++;
	}

	void Print()
	{
		Node* Current = head;
		
		while (Current != nullptr)
		{
			cout << Current->Value << " ";
			Current = Current->next;
		}
		cout << "\n";
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void DeleteFirst()
	{
		if (head == nullptr) return;
		
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			_Size--;
			return;
		}

		Node* tempNode = head;
		head = head->next;
		head->prev = nullptr;
		delete tempNode;
		_Size--;
	}

	void Clear() // is it right?
	{
		Node* TempNode = nullptr;
		while (head != nullptr)
		{
			TempNode = head;
			head = head->next;
			delete TempNode;
		}
		_Size = 0;
		tail = nullptr;
	}
};