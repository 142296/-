#include<bits/stdc++.h>	//快慢指针，删除指定元素
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
			i++;				//快指针快一步
		}
		if (i != j && i < 20)		//不同说明有
		{
			a[j] = a[i];		//后面的元素前移就是删除
		}
	}
	printf("%d", i - j);
}