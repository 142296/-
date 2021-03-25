#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int mycomp(const void* p1, const void* p2)            //�Ӵ�С����   1����Ҫ��
{
	const int* a1 = (const int*)p1;
	const int* a2 = (const int*)p2;
	if (*a1 < *a2)
		return 1;
	else if (*a1 == *a2)
		return 0;
	else
		return -1;
}
int cmp1(const void* a, const void* b)
{
	const int* a1 = (const int*)a;
	const int* b1 = (const int*)b;
	return *a1 < *b1 ? 1 : -1;
}
int main()
{
	int a[100];
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		a[i] = rand() % 100;
	}
	qsort(a, 100, sizeof(int), cmp1);                     //�����������
	for (int i = 0; i < 100; i++)
		printf("%d  ", a[i]);
}
