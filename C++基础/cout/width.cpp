#include<iostream>
using namespace std;
int main()
{
	int width = 4;
	char str[20];
	cout << "请输入一段文本:\n";
	cin.width(5);       //相当于scanf("%5c");
	while (cin >> str)
	{
		cout.width(width++);  //相当于printf("%5d")   以下都执行
		cout << str << endl;
		cin.width(5);
	}
}