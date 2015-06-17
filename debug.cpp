#include <iostream>
#include <fstream>
void usage (char [] [20], int);
int main ()
{
  typedef char truth_table [10] [20];
  truth_table name;
  truth_table name2;
  name2[1] [1] = FALSE;
  usage ()
  std::ofstream debugFile;
  debugFile << "This is the debug information " <<endl;
  
  return 0;
}

void usage ( char name [] [20], int first_size)
{
  
}
