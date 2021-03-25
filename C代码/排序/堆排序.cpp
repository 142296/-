#include<bits/stdc++.h>
int a[20];
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b; *b = t;
}
void max_head(int s,int e)
{
	int dad = s;
	int son = dad * 2 + 1;
	while (son <= e)			
	{
		if (son + 1 <= e && a[son] < a[son + 1])		//找大值
			son++;
		if (a[dad] < a[son])					
			swap(&a[dad], &a[son]);
		dad = son;			//沿大值的树向下   因为更改可能引起连锁反应
		son = dad * 2 + 1;
	}
}
void heap_sort(int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)		//确定每个子树都是堆树
		max_head(i, len - 1);
	for (int i = len - 1; i > 0; i--)		//每次取堆顶
	{
		swap(&a[0], &a[i]);					//交换堆顶和堆底(堆底不再更改)
		max_head(0, i - 1);					//刷新堆顶
	}
}
int main()
{
	srand(time(0));
	int len = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < len; i++)		//初始化
		a[i] = rand() % 100;
	heap_sort(len);
	for (int i = 0; i < len; i++)		//输出
	{
		printf("%d ", a[i]);
	}
}