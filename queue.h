#ifndef MYQUEUE_H
#define MYQUEUE_H
template <class P>
class Queue
{
private:
        struct Node
        {
               P data;
               Node * next;
        };
        Node * Head;
public:
       Queue()
       {
              Head = NULL;
       }
       
};


#endif
