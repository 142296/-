#include<bits/stdc++.h>
using namespace std;
int cmp1(int a, int b)		//1不排
{
	return a > b;
}
int main()
{
	int a[100];
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		a[i] = rand() % 100;
	}
	sort(a, a + 100, cmp1);                      //快速排序调用
	for (int i = 0; i < 100; i++)
		printf("%d  ", a[i]);
}
