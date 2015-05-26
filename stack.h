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
		if (Top != NULL)
		{
			while (Top)
			{
				pop();
			}
		}
		if (&obj == *this)
		{
			return;
		}

		else
		{
			Node * helper1;
			helper1 = obj.Top;
			while (helper1)
			{
				push(helper1->data);
				helper1 = helper1->next;
			}

		}

	}

	//    Stack <Z> & operator=(Stack<Z> &obj)
	//    {
	//
	//        if (&obj == this)
	//        {
	//            return *this;
	//        }
	//        Z value;
	//        //Node * helper1 = Top;
	//        if (!obj.Top)
	//        {
	//            return *this;
	//
	//        }
	//        else
	//        {
	//
	//                Node * helper2 = obj.Top;
	//        //helper2 = obj.Top;
	//                Z temp;
	//                while (helper2)
	//                    {
	//                    // value = helper2->data;
	//                    temp = helper2->data;
	//                    push(temp);
	//                    //helper1->data = push(value);
	//
	//                    helper2 = helper2->next;
	//                    // helper2 = helper2->next;
	//
	//                    }
	//        }
	//        return *this;
	//    }

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
		throw "Error: there are no values on the stack";
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
