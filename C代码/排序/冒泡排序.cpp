#include<stdio.h>        //�����������������Ƚϡ�
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
	for (i = 0; i < size; i++)        //��ֵ
		count[i] = rand() % 100;
	for (i = size - 1; i >0; i--)  //��������
	{
		for (j = 0; j < i; j++)
		{
			max++;
			if (count[j] > count[j + 1])   //�Ƚ���������
				swap(&count[j], &count[j + 1]);
		}
	}
	for (i = 0; i < size; i++)
		printf("%d ", count[i]);
	printf("\n%d��", max);
}