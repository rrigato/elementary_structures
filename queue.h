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
       }
       Queue & operator= (const &obj)
       {
            if (&obj == this)
            {

                return this*;
            }
            if (obj->Front ==NULL)
            {
                return this*;
            }
            Node * helper = obj->Front;
            while (helper)
            {
                enque(helper->data);
                helper = helper->next;
            }

        }

       void enque (P );
       P deque ();
       void menu( char) const;
       void small_menu() const;


};

    template <class P>
    void Queue<P>::small_menu() const
    {
        char choice;
        cout << "(E)nque" <<endl;
        cout << "(D)eque" <<endl;
        cout << "(Q)uit" <<endl;
        menu (choice);
    }

    template <class P>
    void Queue<P>::menu(char letter) const
    {
        switch (letter)
            {
                case 'e':
                    case 'E':  {
                                    cout << "Enque the function " <<endl;
                                    break;
                               }
                    case 'd':
                    case 'D':
                            {
                                cout << "deque the function" <<endl;
                                break;
                            }
                    case 'q':
                    case 'Q':
                            {
                                cout << "bye bye " <<endl;
                                return;
                            }
                    default:
                            {
                                cout << " Bad user hit a proper value "<<endl;
                            }
            }
                small_menu();
    }


template <class P>
P Queue<P>::deque()
{
    if (!Front)
    {
        throw "The queue is empty";
    }
    else
    {
        P value;
        Node * helper1 = Front;
        Front = Front->next;
        value = helper1->data;
        delete helper1;
        return value;
    }
}
 template <class P>
 void Queue<P>::enque(P value)
{
      Node * NewNode;
      NewNode = new Node;
      NewNode->data = value;
      Node * helper1 = Front;
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
