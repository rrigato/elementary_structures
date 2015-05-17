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
			Node newNode;
			Head->
			
		}

		*this = obj;
	}*/
	void push(Z);
	Z pop();
};

template <class Z>
void Stack<Z>::push (Z type)
{
	newNode = new Node;
	newNode->next = Head;
	Head = newNode;
	newNode->data = type;
}

template <class Z>
Z Stack<Z>::pop()
{
	if (!Head)
	{ throw "Error: there are no values on the stack"}
	else 
	{
		Z returned;
		returned = Head->Node;
		Node * one = Head;
		Head = Head->next;
		delete one;
	}


}
