#include<stdio.h>
#include<stdlib.h>
#define one 1

void swap(int* p, int* q);
int judge(int a, int b, int c);
void show(int a[]);

void swap(int* p, int* q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}
int judge(int a, int b, int c)
{
	return a + b + c == (one + 4) * 3;
}
void show(int a[])
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			printf("\n");
		printf("%d ", a[i]);
	}
}

int main()
{
	int num[9];
	int i, j, end = 0;
	for (i = 0, j = one; i < 9; i++, j++)
	{
		num[i] = j;
	}
	while (1)
	{
		for (i = 0; i < 9; i++)      //交换两个数
		{
			if (i == 4 || i == 8)
				continue;
			while (1)
			{
				j = (rand() % (9 - i)) + i;
				if (j != 4 && j > i)
				{
					swap(&num[i], &num[j]);
					break;
				}
			}
		}
		if (judge(num[1], num[2], num[0]))
			if (judge(num[3], num[4], num[5]))
				if (judge(num[6], num[7], num[8]))
					if (judge(num[0], num[3], num[6]))
						if (judge(num[1], num[4], num[7]))
							if (judge(num[2], num[5], num[8]))
								if (judge(num[0], num[4], num[8]))
									if (judge(num[2], num[4], num[6]))
									{
										printf("right:");
										show(num);
										printf("\n");


									}
	}
}