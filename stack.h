#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <string>
using namespace std;
template <class Z>
class Stack
{
private:
	struct Node
	{
		Z data;
		Node* next;
	};
	Node * Top;
public:
	Stack()
	{
		Top = 0;
	}
	Stack(Stack &obj)
	{
		*this = obj;
	}
	void push(Z);
	Z pop();
	bool isEmpty() const;
	bool isFull() const;
	void operator= (const Stack &obj)
	{
		if (obj.Top == NULL)
		{
			return;
		}

		if (&obj == this)
		{
			return;
		}
		if (Top != NULL)
		{
			while (Top)
			{
				pop();
			}
		}

		else
		{
			Node * helper1;
	//		Node * helper2;
			helper1 = obj.Top;
			copy_help(helper1);

		}

	}
	void copy_help(Node * helper1)
	{
		if (helper1 == NULL)
		{
			return;
		}
		else
		{
			copy_help(helper1->next);
			push(helper1->data);
		}
	}
};


template <class Z>
bool Stack <Z>::isFull() const
{
	return false;
}

template <class Z>
bool Stack <Z>::isEmpty()const
{
	if (!Top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class Z>
void Stack<Z>::push(Z value)
{
	Node * newNode;
	newNode = new Node;
	newNode->data = value;
	if (!Top)
	{
		Top = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = Top;
		Top = newNode;
	}
}

template <class Z>
Z Stack<Z>::pop()
{
	if (!Top)
	{
		string mistake = "Error: there are no values on the stack";
		throw mistake;
	}
	else
	{
		Z value;
		value = Top->data;
		Node * one = Top;
		Top = Top->next;
		delete one;
		return value;
	}
}
#endif
