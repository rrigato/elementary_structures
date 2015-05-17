#include <iostream>
#include <fstream>
using namespace std;
class LinkedList
{
private:
    struct Node
    {
        char value;
        Node * Next;
    };
    Node * head;
public:
    LinkedList()
        { 
            head =NULL;
            small_menu();
        }
    ~LinkedList()
        {
            destroy();
        }
      
    void print() const; //works
    void Insert (); 
    void Remove( char); 
    bool Write() const; //works
    bool Read () const; //works
    void destroy();
    bool search(char);//works
    void small_menu();
    void menu (char);
    void print_menu ();
    int length() const;
    void Reverse() const;
    void Reverse(Node *)const;
};
int main()
{
    LinkedList start;
    cin.get();
    return 0;
}
  
 void LinkedList::Reverse() const
 {
      Node * one, *two;
      one = head; two = head->Next;
      for(; two->Next != NULL; one = two, two = two->Next); 
      Reverse(two);
 }
 void LinkedList::Reverse(Node * two) const
 {
      cout << two->value;
      if (two ==head)
      { return;}
      else
      {
          Node *x, *y;
          x = head; y = head->Next;
          while(y!=two)
          {
               x=y; y=y->Next;
          }
          Reverse(x);
      }
 }
int LinkedList::length()const
{
    Node * one = head;
    int count = 0;
  
          
        while(one)
        {
            one = one->Next;
            count++;
        }
          
  
    return count;
}
bool LinkedList::search(char letter)
{
    if (!head)
    {return false;}
      
    if(head->value == NULL)
    {
        if(head->value == letter)
        {
            return true;
        }
        else { return false;}
    }
    Node *one = head;
    Node *two = head->Next;
    for (; one->value != letter &&two!= NULL; one = two, two = two->Next);
    if (one->value==letter)
    {return true;}
    return false;
}
void LinkedList::destroy()
{
      
    Node *p = NULL;
    while (head)
    {
        p = head;
        head = head->Next;
        delete p;
  
    }
}
bool LinkedList::Read() const
{
    char input;
    fstream f;
    f.open("list.dat", ios::in);
    if (f)
    {
        while(f >>input)
        {
            cout <<input;
        }
        f.close();
        return true;
           
    }
    f.close();
    return false;
       
}
bool LinkedList::Write() const
{
    Node * q;
    q = head;
    fstream f;
    f.open("list.dat", ios::out);
  
    if (f)
    {
        while (q)
        {
            f << q->value;
            q = q->Next;
        }
        f.close();
        return true;
    }
    f.close();
    return false;
}
void LinkedList::Remove(char letter)
{
    if (!head)
    {
        return;
    }
    if (head->Next ==NULL)
    {
        if (head->value == letter)
        {delete head;}
        else
            {return;}
    }
    Node * one = head;
    Node * two = one->Next;

        for (one = head, two = head->Next; two != NULL && two->value != letter; one = two, two = two->Next);
        if (two!=NULL)
        {
             one->Next = two->Next;
             delete two;
        }
 
}
void LinkedList::Insert()
{
  
    char letter;
    cout << "Enter a letter to insert" <<endl;
    cin >> letter;
    Node * p, * q;
    
    Node * newNode = new Node;
    newNode->value = letter;
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = NULL;
    }
    else if(newNode->value <head->value)
    {
        newNode->Next = head;
        head = newNode;
    }
/*    else if (head->Next == NULL)
    {
        if(letter < head->value)
        {
    
            newNode->Next = head;
            head = newNode;
            
        }
        else
        {
            head->Next = newNode;
            newNode->Next = NULL;
              
        }
  
          
    }*/
    else
    {
     for (q = head, p = head->Next; p != NULL && newNode->value > p->value; q = p, p = p->Next);
  
     newNode->Next = p;
     q->Next = newNode;
    }
    
    

}
