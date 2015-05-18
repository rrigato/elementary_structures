#ifndef MYSTACK_H
#define MYSTACK_H
template <class Z>
class Stack
{
private:
	struct Node
	{
		Z data;
		Node* next;
	};
	Node * Head;
public:
	Stack()
	{
		Head = NULL;
	}
	/*Stack (Stack &obj)
	{

		Node *one = obj.Head;
		Head = one;
		one = one->next;
		while (one)
		{
			newNode = new Node;

			
		}

		*this = obj;
	}*/
	void push(Z);
	Z pop();
	bool isEmpty () const;
	bool isFull() const;
	Stack & operator=(const Stack &obj)
	{
		if (&obj ==*this)
		{ return *this;}
		Node * helper1 = Head;
		Node * helper2 = obj.Head;
		Z value = helper2->data;
		while(helper2)
		{
			helper1-> data = value;
			helper1 = helper1->next;
			helper2= helper2->next;
		}
		return *this;
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
	if(!Head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class Z>
void Stack<Z>::push (Z value)
{
	newNode = new Node;
	newNode->data = value;
	if (!Head)
	{
		Head = newNode;
	}
	else
	{
		newNode->next = Head;
		Head = newNode;
	}
}

template <class Z>
Z Stack<Z>::pop()
{
	if (!Head)
	{ throw "Error: there are no values on the stack"}
	else 
	{
		Z value;
		value = Head->Node;
		Node * one = Head;
		Head = Head->next;
		delete one;
		return value;
	}
}




#endif
