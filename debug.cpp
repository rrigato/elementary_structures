#include <iostream>
#include <fstream>
void usage (char [] [20], int);
int main ()
{
  //example of a truth table
  typedef char truth_table [10] [20];
  truth_table name;
  truth_table name2;
  name2[1] [1] = FALSE;
  name [5] [1] = TRUE;
  
  usage (name2[] [1], 1);
  std::ofstream debugFile;
  debugFile << "This is the debug information " <<endl;
  
  return 0;
}

void usage ( char name [] [20], int first_size)
{
  cout << name2[1] [1] ;
  cout << name [5] [1] ;
}
