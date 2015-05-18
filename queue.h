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
       Queue( Queue & obj)
       {
              Head = obj.Head
              Node * helper1;
              helper1 = obj.Head;
              Node * helper2 = head;
              while (helper1)
              {
                    helper2->next = helper1->next;
              }
       }
       Queue & operator=(const Queue &obj)
       {
              if (&obj ==*this)
               { return *this;}
              Node * helper1 = Head;
              Node * helper2 = obj.Head;
              P value = helper2->data;
              while(helper2)
                 {
                   helper1-> data = value;
                   helper1 = helper1->next;
                   helper2= helper2->next;
                   value = helper2->data;
                 }
              return *this;
       }
       
};


#endif
