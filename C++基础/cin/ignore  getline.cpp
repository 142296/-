#include<iostream>
using namespace std;
int main()
{
	char a[10];
	cin.ignore(7);          //ºöÂÔn¸ö
	cin.getline(a, 9);		//get(n-1)¸ö
	cout << a << endl;
}