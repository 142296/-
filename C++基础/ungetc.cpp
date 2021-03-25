#include<iostream>
using namespace std;
int main()
{
	int a;
	cout << cin.peek() << endl;
	cin >> a;
	ungetc(a, stdin);   //把a返回给输入流
	cout << a;
}