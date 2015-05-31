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
    void Insert (Node*, Z);
    void Destroy (Node* r)
    {
        if (r==NULL)
            return;
        Destroy(r->Left);
        Destroy(r->Right);
        delete r;
        r=NULL;
    }
