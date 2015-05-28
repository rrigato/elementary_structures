#include "MyStack.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{

    string s;
    cout << "Give me a string and I will reverse it " << endl;
    getline(cin, s);
//  int length = s.size();
    Stack <char> start;
    int counter = 0;
    while (counter < s.size())
    {
        start.push(s[counter]);
        counter ++;
    }


    try
    {
        counter = 0;
        while (counter < s.size())
        {
            cout << start.pop() ;
            counter++;
        }
    }
    catch (string mistake)
    {
        cout << mistake << endl;
    }
    cin.get();
    return 0;
}
}
