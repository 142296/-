#include<bits/stdc++.h>	//����ָ�룬ɾ��ָ��Ԫ��
using namespace std;
int main()
{
	srand(time(0));
	int a[20];
	int i, j;
	for (int i = 0; i < 20; i++)
		a[i] = rand() % 10;
	int del;
	cin >> del;
	for (i = 0, j = 0; i < 20; i++, j++)
	{
		if (a[i] == del)
		{
			i++;				//��ָ���һ��
		}
		if (i != j && i < 20)		//��ͬ˵����
		{
			a[j] = a[i];		//�����Ԫ��ǰ�ƾ���ɾ��
		}
	}
	printf("%d", i - j);
}