#include<iostream>
using namespace std;
int main()
{
	int width = 4;
	char str[20];
	cout << "������һ���ı�:\n";
	cin.width(5);       //�൱��scanf("%5c");
	while (cin >> str)
	{
		cout.width(width++);  //�൱��printf("%5d")   ���¶�ִ��
		cout << str << endl;
		cin.width(5);
	}
}