#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i, sum = 0, ch;
	while (cin.peek() != '\n')    //�ж���һ�������Ƿ�Ϊ�س�����ֵΪ�ַ��� 
	{
		//cin.get()  ==getchar() �̵���һ������
		cin >> i;
		sum += i;
	}
	cout <<sum << endl;
}