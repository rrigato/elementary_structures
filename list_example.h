#ifndef LIST_H
#define LIST_H

class List
{
	private:
		struct Node
		{
			int i;
			Node * Next;
		};
		Node * Head;
		void append(int);
	public:
		List();




};

List::List()
{
	Head = 0;
}
void List::append(int z)
{
	Node * newNode = new Node;
	Node->i = z;
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

