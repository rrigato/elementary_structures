#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
class List
{
	private:
		struct Node
		{
			int i;
			Node * Next;
		};
		Node * Head;

	public:
		List();
		~List()
		{
			clear();
		}
		List(const List & l)
		{
			Head = 0;
			*this = l;
		}
		void append(int);
		void print() const;
		bool isEmpty() const;
		void clear();
		void remove(int);
		void insert(int);
		List & operator = (const List &);




};

List::List()
{
	Head = 0;
}
void List::append(int z)
{
	Node * newNode = new Node;
	newNode->i = z;
	newNode->Next = 0;
	if (Head == 0)
	{
		Head = newNode;
	}
	else
	{
		Node * one = Head;
		while (one->Next)
		{
			one = one->Next;
		}

		one->Next = newNode;
	}


}

void List::print()const
{
	Node * one = Head;
	while (one)
	{
		cout << one->i << " ";
		one = one->Next;
	}
}

bool List::isEmpty() const
{
	if (Head)
	{
		return false;
	}
	else
		return true;
}
void List::clear()
{
	Node * one = Head;
	while (one)
	{
		Head = Head->Next;
		delete one;
		one = Head;
	}
}

void List::remove(int value)
{
	if (isEmpty())
		throw "List underflow error! /n";
	Node * one = Head;
	if (Head->i == value)
	{
		Head = Head->Next;
		delete one;
	}
	else
	{
		Node * two = one->Next;
		for (; two != 0 && two->i != value; one = one->Next, two = two->Next);
		if (two)
		{
			one->Next = two->Next;
			delete two;

		}
		else
		{
			throw "Value not found";
		}
	}
	
}

void List::insert(int value)
{
	Node * newNode = new Node;
	newNode->i = value;
	newNode->Next = 0;
	if (isEmpty())
	{
		Head = newNode;

	}
	else if (value < Head->i)
	{
		newNode->Next = Head;
		Head = newNode;
	}
	else
	{
		Node * one = Head;
		Node * two = Head->Next;
		for (; two != 0 && two->i < value; one = one->Next, two = two->Next);
		newNode->Next = two;
		one->Next = newNode;
	}
}

List & List::operator=(const List &l)
{
	if (this == &l)
		return *this;
	if (isEmpty())
	{
		clear();
	}
	Node * one = l.Head;
	while (one)
	{
		insert(one->i);
		one = one->Next;
	}
}
#endif
