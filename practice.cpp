#include <iostream>
using namespace std;
//increasing list
class linked_list
{

		struct Node
		{
			int data;
			Node * Next;
		};


		Node * Head;


		void insert( int );
};

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
