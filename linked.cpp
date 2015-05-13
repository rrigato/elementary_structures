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
};
int main()
{
    LinkedList start;
	char letter = 'A';
	start.Insert();
	start.Insert();

	bool test =start.search(letter);
	if (test)
		cout << "It worked" <<endl;
	cin.get();
	cin.get();
    return 0;
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
