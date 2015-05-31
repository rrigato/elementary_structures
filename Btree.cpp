#include <iostream>
#include "Btree.h"
using namespace std;
int main()
{
    Btree <int> test;
    test.Insert(3);
    test.Insert(5);
    test.Insert(7);
    test.Insert(6);
    test.Insert(2);
    test.preprint();
    test.Remove(5);
    test.preprint();
    cin.get();
    return 0;
}
