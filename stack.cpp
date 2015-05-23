
#include "MyStack.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    try
    {
        Stack<int> start;
        start.push(2);
        start.push(3);
        // Stack<int> part2(start);
        Stack<int> part3;
        part3 = start;

        std::cout << start.pop() << std::endl;
        //std::cout << part2.pop() <<std::endl;
        //  std::cout << part3.pop() <<std::endl;
        std::cin.get();
    }
    catch (string mistake)
    {
        cout << mistake << endl;
    }
    return 0;
}
