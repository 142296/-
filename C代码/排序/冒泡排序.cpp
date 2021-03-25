#include<stdio.h>        //从左往右依次两两比较。
#include<stdlib.h>

void swap(int* p, int* q)
{
	int t = *p;
	*p = *q;
	*q = t;
}
int main()
{
	int size, i, j, count[10], max = 0;
	size = sizeof count / sizeof count[0];
	for (i = 0; i < size; i++)        //赋值
		count[i] = rand() % 100;
	for (i = size - 1; i >0; i--)  //划定界限
	{
		for (j = 0; j < i; j++)
		{
			max++;
			if (count[j] > count[j + 1])   //比较连续两数
				swap(&count[j], &count[j + 1]);
		}
	}
	for (i = 0; i < size; i++)
		printf("%d ", count[i]);
	printf("\n%d次", max);
}