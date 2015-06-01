
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
    void Insert (Node * r, Z data)
    {

        if (r ==NULL)
            {
                Node * newNode;
                newNode = new Node;
                newNode->value =data;
                newNode->Left = NULL;
                newNode->Right = NULL;
                r = newNode;

            }
        else if(r->value > data)
        {
            Insert(r->Left, data);
        }
        else
        {
            Insert(r->Right,data);
        }
    }
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
    void preprint(Node * r)
    {
        if (r == NULL)
            return;
        preprint(r->Left);
        std::cout << r->value;
        preprint(r->Right);
    }
    bool Search(Node * r, Z data)
    {
        if (r==NULL)
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
            Search(r->Left,data);
        }
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
        void Search(Z data)
        {
            Search(Root,data);
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
    }
    void preprint()
    {
        preprint(Root);
    }
};

/*template <class Z>
void Btree<Z>::Insert(Node * r, Z data)
{

    if (r ==NULL)
        {
            Node * newNode;
            newNode = new Node;
            newNode->value =data;
            newNode->Left = NULL;
            newNode->Right = NULL;
            r = newNode;

        }
    else if(r->value > data)
    {
        Insert(r->Left, data);
    }
    else
    {
        Insert(r->Right,data);
    }
}*/
#endif // BTREE_H

