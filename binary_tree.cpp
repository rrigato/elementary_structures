#include <iostream>
using namespace std;
struct TreeNode;
void destroy(TreeNode *&);
struct TreeNode
{
	int value;
	TreeNode* Left;
	TreeNode * Right;
	TreeNode * Root;
};
void seek(TreeNode*& r, int t)
{
	if (r == NULL)
		return;
	if (r->value == t)
		destroy(r);
	if (t < r -> value)
		seek(r->Left, t);
	else
		seek(r->Right, t);

}

void destroy(TreeNode *& r)
{
	if (r->Left == NULL && r->Right == NULL)
	{
		delete r;
		r = NULL;
		return;
	}
	TreeNode * p = NULL;
	if (r->Left != NULL && r->Right == NULL)
	{
		p = r;
		r = r->Left;
		delete p;
		return;
	}
	if (r->Left == NULL && r->Right != NULL)
	{
		p = r;
		r = r->Right;
		delete p;
		return;
	}
	else
	{
		p = r->Right;
		while (p->Left != NULL)
		{
			p = p->Left;
		}
		p->Left = r->Left;
		p = r;
		//update root;
		r = r->Right;
		delete p;

		return;

	}
}
 void helper (int);
int main()
{
	return 0;
}

