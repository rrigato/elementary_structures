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
    void seek(Node *r, Z data)
    {
        if (r==NULL)
            return;
        if(r->value == data)
            Remove(r);
        else if (r->value > data)
        {
            seek(r->Left, data);
        }
        else if(r->value < data)
        {
            seek(r->Right, data);
        }
 
    }
    void Remove (Node *r)
    {
        if (r->Left ==NULL && r->Right ==NULL)
        {
            delete r;
            r =NULL;
            return;
        }
        Node * one = NULL;
        if(r->Left !=NULL && r->Right == NULL)
        {
            one = r;
            r = r->Left;
            delete one;
            return;
        }
        else if(r->Right != NULL && r->Left ==NULL)
        {
            one = r;
            r = r->Right;
            delete one;
            return;
        }
        else
        {
            one = r->Right;
            while(r->Left !=NULL)
            {
                one = one->Left;
            }
            one->Left = r->Left;
            one = r;
            r = r->Right;
            delete one;
            return;
        }
    }
