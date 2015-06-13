#include <iostream>
#include "Btree.h"
using namespace std;
void menu();
int main()
{
	cout << "this is a test run" ;
	menu();

	return 0;
}

void menu()
{
	Btree <int> test;
	char choice;
	do
	{
		cout << endl;
		cout << "(C)ount"  << endl;
		cout << "(I)nsert" << endl;
		cout << "(R)emove" << endl;
		cout << "(P)rint " << endl;
		cout << "(Q)uit"   << endl;
		cout << "(S)earch" << endl;

		cin >> choice;
		switch (choice)
		{
		case 'C':
		case 'c':	{
					test.count();
					}


		case  'I':
		case  'i':   {
			int value;
			cout << "Give me a value and I will insert it " << endl;
			cin >> value;
			test.Insert(value);
			break;
		}

		case 'P':
		case 'p':   {
			test.preprint();
			break;

		}

		case 'R':
		case 'r':   {
			int value;
			cout << "Give me a value and I will remove it " << endl;
			cin >> value;
			test.Remove(value);
			break;
		}
		case 'q':
		case 'Q':
		{
			cout << "Bye Bye" << endl;
			return;
		}

		case 's':
		case 'S':
		{
			int value;
			cout << "Give me a value and I will search for it " << endl;
			cin >> value;
			if (test.Search(value))
				cout << "It was found in the binary tree!" << endl;
			else
				cout << "It was not found in the binary tree." << endl;
			break;
		}

		default: cout << "Bad user, enter a proper choice." << endl;


		}
	} while (1);
}
