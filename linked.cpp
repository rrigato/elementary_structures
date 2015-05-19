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
      
    void print() const; 
    void Insert (); 
    void Remove( char); 
    bool Write() const; 
    bool Read () const; 
    void destroy();
    bool search(char) const;
    void small_menu() ;
    void menu (char);
    void print_menu () ;
    int length() const;
    void Reverse() const;
    void Reverse(Node *)const;
};
int main()
{
    LinkedList start;
    //cin.get();
    return 0;
}
  
 void LinkedList::Reverse() const
 {
      Node * one, *two;
      one = head; two = head->Next;
	  if (!one)
	  {
		  cout << "There are no values in the list to reverse" <<endl;
	  }
	  else if (two)
	  {
		 for(; two->Next != NULL; one = two, two = two->Next); 
		 Reverse(two);
	  }
	  else
	  {
		  cout << "There is only one value in the list to reverse " <<endl;
	  }
 }
 void LinkedList::Reverse(Node * two) const
 {
      cout << two->value;
      if (two ==head)
      { cout <<endl; return;}
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
bool LinkedList::search(char letter) const
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
        {
			delete head;
			head= NULL;
          
		}
		  return;
    }
    Node * one = head;
    Node * two = one->Next;

        
        if (two!=NULL)
        {
			for (one = head, two = head->Next; two != NULL && two->value != letter; one = two, two = two->Next);
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
    
    
    /*
    Node * NodePtr = head->Next;
    while(*/
}
void LinkedList::print ()const
{
    Node * one = head;
    while (one)
    {
        cout << one->value << " " ;
        one = one->Next;
    }
    cout <<endl;
}
    
    
    
    
    
void LinkedList::menu (char letter)
{
    switch(letter)
    {
	case 'c':
    case 'C': {
				destroy();//cout << "calling the clear function" <<endl;
                break;
              }

	case 'd':
    case 'D': {
			   char Delete; cout << "Enter the value to delete" <<endl;
               cin>>Delete; Remove(Delete);//cout << "Delete a character for the linked list" <<endl;
               break;
              }

	case 'g':
    case 'G': { 
				Read();
                cout <<endl;//cout << "Load the linked list." <<endl;
                break;
              }

	case 'i':
    case 'I': {
				Insert(); //cout << "Insert into the linked list" <<endl;
                break;
              }

	case 'l':
    case 'L': {  
				 int returned; returned = length(); 
                 cout <<"The linked list has " <<returned << " nodes" <<endl; // cout << "Returns the length of the linked list" <<endl;
                 break;
              }

	case 'm':
    case 'M': 
			  {
				print_menu();
                break;
              }

	case 'p':
    case 'P': { 
				print(); //cout << "Display the contents of the linked list " <<endl;
                break;
              }

	case 'q':
    case 'Q': {
				cout <<"Bye Bye" <<endl;//cout << "Terminates the program." <<endl;
                return;
                break;
              }

	case 'r':
    case 'R': { Reverse(); //cout << "Extra credit display linked list in reverse." <<endl;
				break;
			  }
    
	case 's':
	case 'S': {
				char searching; cout << "Enter a value to search for" <<endl;
                cin >>searching; 
                bool returned = search(searching); 
				if (returned)
				{cout << "The value was found." <<endl;}
				else 
				{cout << "The value was not found." <<endl;}
				//cout << "Search for a value in the linked list " << endl;
                break;
              }
    
	case 'w':
	case 'W': {Write(); //cout << "Writes the linked list to the disk." <<endl;
                break;
              }
    
	default : {
				cout << "Bad user, please enter a proper menu choice" <<endl;
				small_menu();
			  }
    }
    small_menu();
}
    
void LinkedList::print_menu ()
{
    //char choice;
    cout << "Please chose an option from the menu..." <<endl;
    cout << "'C' Clears the linked list." <<endl;
    cout << "'D' Deletes a character for the linked list." <<endl;
    cout << "'G' Loads the linked list from disk." <<endl;
    cout << "'I' Insert into the linked list" <<endl;
    cout << "'L' Returns the length of the linked list" <<endl;
    cout << "'M' Displays the menu" <<endl;
    cout << "'P' Display the contents of the linked list " <<endl;
    cout << "'Q' Terminates the program." <<endl;
    cout << "'R' Extra credit display linked list in reverse." <<endl;
    cout << "'S' Search for a value in the linked list " << endl;
    cout << "'W' Writes the linked list to the disk." <<endl;
    small_menu();
/*    cout << "Enter your choice" <<endl;
    cin >> choice;
    menu(choice);
*/
}
    
void LinkedList::small_menu () 
{
    cout <<"(C)lear" <<endl;
    cout <<"(D)elete" <<endl;
    cout <<"(G)et" <<endl;
    cout <<"(I)nsert" <<endl;
    cout <<"(L)ength" <<endl;
    cout <<"(M)enu" <<endl;
    cout <<"(P)rint" <<endl;
    cout <<"(Q)uit" <<endl;
    cout <<"(R)everse"<<endl;
    cout <<"(S)earch" <<endl;
    cout <<"(W)rite" <<endl;
    char choice;
    cin >> choice;
    menu(choice);
    
}
