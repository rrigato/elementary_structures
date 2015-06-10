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
		void preorder (Node *&) const;
		bool Search (Node * &, int) const;
		void Seek(Node *&, int);
		void Destroy(Node *&);

};

void binary_tree::Seek (Node * & r, int data)
{
	if (r==0)
		throw "The value was not found";
	else if (r->value ==data)
	{Destroy(r);}
	else if (r->value > data)
		Search(r->Left, data);
	else 
		Search(r->Right,data);
}
void binary_tree::Destroy(Node *&r)
{
	if (r->Right == NULL && r->Left ==NULL)
	{delete r; r=NULL; return; }
	else if (r->Right != NULL && r->Left ==NULL)
	{
		Node * one = r;
		r = r->Right;
		delete one;
		return;
	}
	else if (r->Right == NULL && r->Left !=NULL)
	{
		Node * one = r;
		r = r->Left;
		delete one;
		return;
	}
	else
	{
		Node * one = r->Right;
		while(one->Left)
		{
			one = one->Left;
		}
		one->Left = r->Left;
		one = r;
		r = r->Right;
		delete one;
	}
}



bool binary_tree::Search (Node *&r, int data)const
{
	if (r==0)
		return false;
	else if (r->value ==data)
		return true;
	else if (r->value > data)
		return Search(r->Left, data);
	else 
		return Search(r->Right,data);

}

void binary_tree::preorder(Node *& r)const
{
	if (!r)
		return;
	else
	{
		cout << r->value << " " <<endl;
		preorder(r->Left);

		preorder(r->Right);
	}
}
void binary_tree::insert(Node *& r, int data)
{

	if (!r)
	{
		Node * newNode = new Node;
		r = newNode;
		r->value = data;
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
