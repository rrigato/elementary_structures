#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void Reverse (string);
 
int main ()
{
    string obj;
    cout << "Write a string and I will reverse it for you" <<endl;
    getline(cin, obj); //Gets the whole string until the user hits enter
    Reverse(obj);
    return 0;
}
 
void Reverse (string obj)
{
     int length = obj.length();
     if (length == 0)
     {
                return;
     }
     else
     {
         cout << obj[length-1]<<endl;
         int counter = 0;
         string temp;
         while (counter!=(length-2))
         {
               temp[counter] = obj[counter];
         }
         Reverse(temp);
     }   
}
/*
void Reverse(string obj)
{
     char * c_string = new char[obj.length()+1];
    strcpy (c_string, obj.c_str());
     if (c_string[0]== '\0')
     {
          delete [] c_string; //deletes last c-string and then returns
          return;
     }
     else
     {
         cout << c_string[0]
          string temp
     }
     delete [] c_string; //deletes all other c_strings before function dies
}
*/
