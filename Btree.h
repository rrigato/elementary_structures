#include <iostream>
#ifndef BTREE_H
#define BTREE_H
template <class Z>
class Btree
{
private:
	struct Node
	{
		Z value;
		Node * Left;
		Node * Right;
	};
	Node * Root;
	void Insert(Node*&, Z);
	void Destroy(Node * &);

	void seek(Node * &, Z);

	void Remove(Node * &);



	void preprint(Node * &)const;

	bool Search(Node * &, Z) const;
	int num_nodes;
	int private_count()
	{
		return num_nodes;
	}

public:
	Btree()
	{
		Root = NULL;
	}
	~Btree()
	{
		Destroy();
	}
	bool Search(Z data)
	{
		return Search(Root, data);
	}
	void Remove(Z data)
	{
		seek(Root, data);
	}
	void Destroy()
	{
		Destroy(Root);
	}
	void Insert(Z data)
	{
		Insert(Root, data);
		num_nodes++;
	}
	void preprint()
	{
		preprint(Root);
	}
	int count()
	{
		return private_count();
	}
};


template <class Z>
void Btree<Z>::preprint(Node * & r) const
{
	if (r == NULL)
		return;
	std::cout << r->value << " ";
	preprint(r->Left);
	preprint(r->Right);
}


template <class Z>
bool Btree<Z>::Search(Node * & r, Z data) const
{
	if (r == NULL)
		return false;
	if (r->value == data)
	{
		return true;
	}
	else if (r->value < data)
	{
		Search(r->Right, data);
	}
	else if (r->value > data)
	{
		Search(r->Left, data);
	}
}

template <class Z>
void Btree<Z>::Remove(Node * & r)
{
	if (r->Left == NULL && r->Right == NULL)
	{
		delete r;
		r = NULL;
		num_nodes--;
		return;
	}
	Node * one = NULL;
	if (r->Left != NULL && r->Right == NULL)
	{
		one = r;
		r = r->Left;
		delete one;
		num_nodes--;
		return;
	}
	else if (r->Right != NULL && r->Left == NULL)
	{
		one = r;
		r = r->Right;
		delete one;
		num_nodes--;
		return;
	}
	else
	{
		one = r->Right;
		while (r->Left != NULL)
		{
			one = one->Left;
		}
		one->Left = r->Left;
		one = r;
		r = r->Right;
		delete one;
		num_nodes--;
		return;
	}

}


template <class Z>
void Btree<Z>::seek(Node * & r, Z data)
{
	if (r == NULL)
		return;
	if (r->value == data)
		Remove(r);
	else if (r->value > data)
	{
		seek(r->Left, data);
	}
	else if (r->value < data)
	{
		seek(r->Right, data);
	}

}



template <class Z>
void Btree<Z>::Destroy(Node * & r)
{
	if (r == NULL)
		return;
	Destroy(r->Left);
	Destroy(r->Right);
	delete r;
	r = NULL;
	num_nodes = 0;
}
template <class Z>
void Btree<Z>::Insert(Node * & r, Z data)
{

	if (r == NULL)
	{
		Node * newNode;
		newNode = new Node;
		newNode->value = data;
		r = newNode;
		newNode->Left = NULL;
		newNode->Right = NULL;
	}
	else if (r->value > data)
	{
		Insert(r->Left, data);
	}
	else
	{
		Insert(r->Right, data);
	}

}
#endif // BTREE_H
