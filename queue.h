
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

};

//    template <class P>
//    void Queue<P>::small_menu() const
//    {
//        char choice;
//        cout << "(E)nque" <<endl;
//        cout << "(D)eque" <<endl;
//        cout << "(Q)uit" <<endl;
//        cin >> choice;
//        menu (choice);
//    }
//
//    template <class P>
//    void Queue<P>::menu(char letter) const
//    {
//        switch (letter)
//            {
//                case 'e':
//                    case 'E':  {
//                                    int value = num_nodes +1;
//                                    Enque (value);
//                                    cout << "Customer number " << value << " now in line!" <<endl;
//                                    cout << "There are now " << num_nodes << " customers in line!" <<endl;
//                                    break;
//                               }
//                    case 'd':
//                    case 'D':
//                            {
//                                cout << "Deque the function" <<endl;
//                                break;
//                            }
//                    case 'q':
//                    case 'Q':
//                            {
//                                cout << "bye bye " <<endl;
//                                return;
//                            }
//                    default:
//                            {
//                                cout << " Bad user hit a proper value "<<endl;
//                                small_menu();
//                            }
//            }
//                small_menu();
//    }


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
