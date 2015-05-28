#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void Reverse(string &);

int main()
{
	string Obj;
	cout << "Write a string and I will reverse it for you" << endl;
	getline(cin, Obj); //Gets the whole string until the user hits enter
	Reverse(Obj);
	cin.get();
	return 0;
}

void Reverse(string & Obj)
{

	static int j = Obj.length() - 1;
	if (j < 0)
	{
		return;
	}
	else
	{

		cout << Obj[j] ;
		j--;
		Reverse(Obj);
	}
}
