#include <iostream>
using namespace std;
void menu (char);
void print_menu ();
void small_menu();
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
		{ head =NULL;}
	/*~LinkedList()
		{
			while (head)
			{
				head->
			}
		}
	*/
	void Insert (char);
};
int main()
{
	LinkedList start;
	start.Insert('C');
	start.Insert('B');
	return 0;
}
void LinkedList::Insert(char letter)
{
	if (head == NULL)
	{ 
		Node * headnode = new Node;
		head = headnode;
		head->value = letter;
		head->Next =NULL;
	}
	if (head->Next ==NULL)
	{
		if(head->value > letter)
		{
			Node * newNode;
			newNode = new Node;
			newNode->value = letter;
			newNode->Next = head;
			head= newNode;
		}
	}
	cout << head->value <<endl;
	//cout << newNode->value <<endl;
	/*
	Node * NodePtr = head->Next;
	while(*/
}

void menu (char letter)
{
	switch(letter)
	{
	case 'C': cout << "calling the clear function" <<endl;
			break;
	case 'D': cout << "Delete a character for the linked list" <<endl;
			break;
	case 'G': cout << "Load the linked list." <<endl;
			break;
	case 'I': cout << "Insert into the linked list" <<endl;
			break;
	case 'L': cout << "Returns the length of the linked list" <<endl;
			break;
	case 'M': print_menu();
			break;
	case 'P': cout << "Display the contents of the linked list " <<endl;
			break;
	case 'Q': cout << "Terminates the program." <<endl;
			break;
	case 'R': cout << "Extra credit display linked list in reverse." <<endl;
			break;
	case 'S': cout << "Search for a value in the linked list " << endl;
			break;
	case 'W': cout << "Writes the linked list to the disk." <<endl;
			break;
	default : cout << "Bad user, please enter a proper menu choice" <<endl; 
			small_menu();
			

	}
}

void print_menu ()
{
	char choice;
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

	cout << "Enter your choice" <<endl;
	cin >> choice;
	menu(choice);

}

void small_menu ()
{
	cout << "(C)lear" <<endl;
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
