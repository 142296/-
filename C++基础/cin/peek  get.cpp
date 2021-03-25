#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i, sum = 0, ch;
	while (cin.peek() != '\n')    //判断下一个输入是否为回车返回值为字符型 
	{
		//cin.get()  ==getchar() 吞掉下一个输入
		cin >> i;
		sum += i;
	}
	cout <<sum << endl;
}