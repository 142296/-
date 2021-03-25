#include<stdio.h>
#define n 4
int count = 0;

void swap(int* p, int* q);

void swap(int* p, int* q)
{
	int t = *p;  *p = *q;
	*q = t;     count++;
}
int main()
{
	int num[n] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num[i]);
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[j + 1] < num[j])
				swap(&num[j + 1], &num[j]);
		}
	}
	printf("%d", count);
}