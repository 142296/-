#include<iostream>
using namespace std;
int main()
{
	int a;
	cout << cin.peek() << endl;
	cin >> a;
	ungetc(a, stdin);   //��a���ظ�������
	cout << a;
}