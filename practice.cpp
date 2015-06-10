#include <iostream>
using namespace std;
//increasing list
class linked_list
{
	private:
		struct Node
		{
			int data;
			Node * Next;
		};


		Node * Head;

	public:
		linked_list()
		{
			Head = 0;
		}
		~linked_list()
		{
			//destroy();
		}
		void insert( int );

};

class binary_tree
{
	private:
		struct Node
		{
			int value;
			Node * Left;
			Node * Right;
		};
		Node * Root;
	public:
		void insert( Node * &, int);

};
void binary_tree::insert(Node *& r, int data)
{
	Node * newNode = new Node;
	if (!r)
	{
		r = newNode;
		newNode->Left= 0;
		newNode->Right =0;
		return;
	}
	else if( r->value > data)
		insert(r->Left, data);
	else
		insert(r->Right, data);


}



void linked_list::insert( int value)
{
	Node * newNode = new Node;
	newNode->data = value;
	if (!Head)
	{
		Head = newNode;
		Head->Next = 0;
		return;
	}
	else if (Head->Next ==0)
	{
		if (Head->data > value)
		{
			newNode->Next = Head;
			Head = newNode;
			
		}
		else 
		{
			Head->Next = newNode;
			newNode->Next =0;
		}
		return;
	}
	else 
	{
		Node * one = Head;
		Node * two = Head->Next;
		for (; two != 0 && two->data < value; one = one->Next, two=two->Next);
		if (two)
		{
			newNode->Next = two;
			one->Next = newNode;
			return;
		}
		else
		{
			one->Next = newNode;
			newNode->Next =0;
			return;
		}
	}
}
	

	
	int main ()
{

	return 0;
}
