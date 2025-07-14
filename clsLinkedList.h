#pragma once

using namespace std;

#include <iostream>
#include <vector>

template <class T>

class clsLinkedList {

private:
	class Node
	{
	public:
		T Value;
		Node* next;
	};

	Node* head = nullptr;
	int _Size = 0;

	Node* GetNode(int Position)
	{
		if (Position < 0 || Position >= _Size) return nullptr;

		Node* Current = head;
		int Counter = 0;
		while (Counter != Position)
		{
			Current = Current->next;
			Counter++;
		}
		return Current;
	}

	void InsertAfter(Node* Current, T Value)
	{
		if (Current == nullptr) return;

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->next = Current->next;
		Current->next = NewNode;

		_Size++;
	}

	void PrintReverseHelper(Node* node)
	{
		if (node == nullptr) return;

		PrintReverseHelper(node->next);
		cout << node->Value;
	}

	void PrintRecursiveHelper(Node* node)
	{
		if (node == nullptr) return;

		cout << node->Value << " ";
		PrintRecursiveHelper(node->next);
	}

public:
	~clsLinkedList()
	{
		Clear();
	}

	Node* Find(T Value)
	{
		Node* Current = head;
		while (Current != nullptr)
		{
			if (Current->Value == Value)
				return Current;
			Current = Current->next;
		}
		return nullptr;
	}

	bool Contains(T Value)
	{
		return Find(Value) != nullptr;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	vector<T> ToVector()
	{
		vector<T> vNodes;
		vNodes.reserve(_Size);
		Node* Current = head;
		while (Current != nullptr)
		{
			vNodes.push_back(Current->Value);
			Current = Current->next;
		}

		return vNodes;
	}

	T* ToArray()
	{
		T* Arr = new T[_Size];

		Node* Current = head;
		int Counter = 0;
		while (Current != nullptr)
		{
			Arr[Counter] = Current->Value;
			Current = Current->next;
			Counter++;
		}

		return Arr;
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

	void PrintReverse()
	{
		PrintReverseHelper(head);
		cout << "\n";
	}

	void PrintRecursive()
	{
		PrintRecursiveHelper(head);
		cout << "\n";
	}

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->next = head;
		
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
			head = NewNode;
			_Size++;
			return;
		}
		
		Node* Current = head;
		while (Current->next != nullptr)
		{
			Current = Current->next;
		}

		Current->next = NewNode;
		_Size++;
	}

	void InsertBefore(T TargetValue, T Value)
	{
		if (head == nullptr) return;

		Node* NewNode = new Node;
		NewNode->Value = Value;

		Node* Current = head;
		Node* Previous = nullptr;

		while (Current != nullptr)
		{
			if (Current->Value == TargetValue)
				break;
			Previous = Current;
			Current = Current->next;
		}
		if (Current == nullptr) return;

		if (Current->Value == head->Value)
		{
			NewNode->next = head;
			head = NewNode;
			_Size++;
			return;
		}

		if (Previous != nullptr)
		{
			NewNode->next = Current;
			Previous->next = NewNode;
		}
		_Size++;
	}

	void InsertAfter(T TargetValue, T Value)
	{
		Node* Current = Find(TargetValue);
		InsertAfter(Current, Value);
	}

	void InsertAtPosition(int Position, T Value)
	{
		Node* Current = GetNode(Position);

		if (Current == nullptr) return;

		InsertAfter(Current, Value);
	}

	void DeleteFirst()
	{
		if (head == nullptr) return;

		Node* temp = head;
		head = head->next;
		delete temp;
		_Size--;
	}

	void DeleteLast()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			_Size--;
			return;
		}

		Node* Current = head->next;
		Node* Prev = head;
		while (Current->next != nullptr)
		{
			Prev = Current;
			Current = Current->next;
		}
		
		Prev->next = nullptr;
		delete Current;
		_Size--;
	}

	void DeleteByValue(T Value)
	{
		if (head == nullptr) return;

		if (head->Value == Value)
		{
			DeleteFirst();
			return;
		}

		Node* Current = head->next;
		Node* Prev = head;

		while (Current != nullptr)
		{
			if (Current->Value == Value)
				break;
			Prev = Current;
			Current = Current->next;
		}

		if (Current == nullptr) return;

		Prev->next = Current->next;
		delete Current;
		_Size--;
	}

	void DeleteAtPosition(int Index)
	{
		if (head == nullptr) return;

		if (Index < 0 || Index >= _Size) return;

		if (Index == 0)
		{
			DeleteFirst();
			return;
		}

		Node* Current = head->next;
		Node* Prev = head;

		int Counter = 1;
		while (Counter != Index)
		{
			Prev = Current;
			Current = Current->next;
			Counter++;
		}

		Prev->next = Current->next;
		delete Current;
		_Size--;
	}

	void DeleteDuplicates()
	{
		Node* Current = head;
		while (Current != nullptr)
		{
			Node* Runner = Current->next;
			Node* Prev = Current;

			while (Runner != nullptr)
			{
				if (Runner->Value == Current->Value)
				{
					Prev->next = Runner->next;
					delete Runner;
					Runner = Prev->next;
					_Size--;
				}
				else
				{
				Prev = Runner;
				Runner = Runner->next;
				}
			}
			Current = Current->next;
		}
	}

	void Clear()
	{
		if (head == nullptr) return;

		Node* Next = nullptr;
		while (head != nullptr)
		{
			Next = head->next;
			delete head;
			head = Next;
		}
		_Size = 0;
	}

	void Reverse()
	{
		if (head == nullptr || head->next == nullptr) return;

		Node* Current = head;
		Node* Prev = nullptr;
		Node* Temp;
		while (Current != nullptr)
		{
			Temp = Current->next;
			Current->next = Prev;
			Prev = Current;
			Current = Temp;
		}

		head = Prev;
	}

	bool IsSorted()
	{
		if (head == nullptr || head->next == nullptr) return true;

		Node* Current = head;

		while (Current->next != nullptr)
		{
			if (!(Current->Value < Current->next->Value)) return false;
			Current = Current->next;
		}

		return true;
	}

	clsLinkedList<T> Clone()
	{
		clsLinkedList<T> MyLinkedList;

		if (head == nullptr) return MyLinkedList;

		Node* CloneHead = new Node;
		Node* CloneHeadCurrent = CloneHead;

		Node  * Current = head;

		while (Current != nullptr)
		{
			CloneHeadCurrent->Value = Current->Value;
			Current = Current->next;
			if (Current != nullptr)
			{
				CloneHeadCurrent->next = new Node;			
				CloneHeadCurrent = CloneHeadCurrent->next;
			}
		}
		CloneHeadCurrent->next = nullptr;

		MyLinkedList.head = CloneHead;
		MyLinkedList._Size = _Size;
		return MyLinkedList;
	}
};