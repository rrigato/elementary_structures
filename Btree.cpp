#include <iostream>
#include "Btree.h"
using namespace std;
void menu();
int main()
{

    menu();
    cin.get();
    return 0;
}

void menu()
{
    Btree <int> test;
    char choice;
    do
    {
        cout << endl;
        cout << "(I)nsert" <<endl;
        cout << "(R)emove" <<endl;
        cout << "(P)rint "<<endl;
        cout << "(Q)uit" <<endl;
        cout << "(S)earch" <<endl;

        cin >> choice;
        switch (choice)
        {
           case  'I':
           case  'i':   {
                            int value;
                            cout << "Give me a value and I will insert it " <<endl;
                            cin >> value;
                            test.Insert(value);
                            break;
                        }
