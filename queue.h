#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <string>
#include <iostream>
using namespace std;

template <class P>
class Queue
{
private:
        struct Node
        {
               P data;
              Node * next;
        };
        Node * Front;
        Node * Rear;
        int num_nodes;
public:
       Queue()
       {
              Front = NULL;
              Rear = NULL;
              num_nodes = 0;
//              small_menu();
       }
       void operator= (const Queue &obj)
       {
            if (&obj == this)
            {

                return ;
            }
            if (obj.Front ==NULL)
            {
                return ;
            }
            while(Front)
            {
                Deque();
            }
            Node * helper = obj.Front;
            while (helper)
            {
                Enque(helper->data);
                helper = helper->next;
            }
            num_nodes = obj.num_nodes;
        }

        Queue( const Queue &obj)
        {
            *this = obj;
//            small_menu();

        }

       void Enque (P );
       P Deque ();
       void menu( char) const;
       void small_menu() const;
       bool isFull() const
       {
           return false;
       }

        bool isEmpty() const
        {
            if (!Front)
            {
                return true;
            }
            return false;
        }
        int get_num() const
        {
            return num_nodes;
        }
};

template <class P>
P Queue<P>::Deque()
{
    if (!Front)
    {
        throw "The queue is empty";
        return -1;
    }
    else
    {
        P value;
        Node * helper1 = Front;
        Front = Front->next;
        value = helper1->data;
        delete helper1;
        num_nodes--;
        if(num_nodes == 0)
        {
            Rear = NULL;
        }
        return value;
    }
}
 template <class P>
 void Queue<P>::Enque(P value)
{
      Node * NewNode;
      NewNode = new Node;
      NewNode->data = value;
      if (!Front)
      {
                Front = NewNode;
                Rear = NewNode;

      }
      else
      {

        Rear->next = NewNode;
        Rear = NewNode;

      }
      NewNode->next = NULL;
      num_nodes++;
}

#endif
