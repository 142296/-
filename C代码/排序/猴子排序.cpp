#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define end 10

void judge(int num[]);
void bogo_sort(int num[]);      //ºï×ÓÅÅÐò
void swap(int*, int*);
void show(int num[]);

int count = 0;
void judge(int num[])
{
	int key = 1;
	while (key)
	{
		key = 0;
		for (int i = 0; i < end - 1; i++)
		{
			if (num[i] > num[i + 1])
			{
				bogo_sort(num);
				key = 1;
			}
		}
	}
}
void bogo_sort(int num[])
{
	int j;
	count++;
	for (int i = 0; i < end - 1; i++)
	{
		j = rand() % (end - i) + i;
		if (j > i)
			swap(&num[i], &num[j]);
	}
}
void swap(int* p, int* q)
{
	int t = *p;
	*p = *q;
	*q = t;
}
void show(int num[])
{
	for (int i = 0; i < end; i++)
		printf("%4d ", num[i]);
}
int main()
{
	int over, begin = time(NULL);
	int num[end];
	for (int i = 0; i < end; i++)
	{
		num[i] = rand() % (end * 10);
	}
	show(num);
	printf("\n");
	judge(num);
	over = time(NULL);
	show(num);
	printf("\ntime=%ds\ncount=%d´Î", over - begin, count);
}