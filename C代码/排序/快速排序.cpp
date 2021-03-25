#include<bits/stdc++.h>
int a[10];
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b; *b = t;
}
void quick_sort(int l, int r)
{
	if (l < r)
	{
		int temp = a[l], i, j;
		for (i = l, j = r - 1; i < j;)
		{
			while (i<j && a[j] > temp)				//从后往前找一个大于基准的
				j--;						
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			while (i < j && a[i] < temp)			//从前往后找一个小于基准的
				i++;
			if (i < j) {
				a[j] = a[i];
				j--;
			}
		}
		a[i] = temp;
		quick_sort(l, i);					//递归调用
		quick_sort(i + 1, r);
	}
}
int main()
{
	srand(time(0));
	int len = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < len; i++)		//初始化
		a[i] = rand() % 100;
	quick_sort(0, len);
	for (int i = 0; i < len; i++)		//输出
	{
		printf("%d ", a[i]);
	}
}