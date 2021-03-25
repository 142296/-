#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define side 5

void swap(int*, int*);
void wash(int num[]);
int judge(int num[]);
void show(int num[]);

void swap(int* p, int* q)
{
	int t = *p;
	*p = *q; *q = t;
}
void wash(int num[])
{
	int j;
	for (int i = 0; i < side * side - 1; i++)
	{
		if (i == (side * side) / 2)
			continue;
		while (1)
		{
			j = rand() % (side * side - i) + i;
			if (j > i&& j != (side * side) / 2)
			{
				swap(&num[i], &num[j]); break;
			}
		}
	}
}

int judge(int num[])
{
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, key = 1;
	for (int i = 0; i < side; i++)                  //求和
	{
		sum1 = sum2 = sum3 = sum4 = 0;
		for (int j = 0; j < side; j++)
		{
			sum1 += num[j * side + i];                                      //第i列
			sum2 += num[i * side + j];										//第i行
			sum3 += num[j * side + j];							//正斜行
			sum4 += num[(j + 1) * (side)-j - 1];					//反斜行
		}
		if (sum1 == sum2 && sum1 == sum3 && sum1 == sum4)
			continue;
		else
		{
			key = 0;
			break;
		}
	}
	return key;
}
void show(int num[])
{
	for (int i = 0; i < side * side; i++)
	{
		if (i != 0 && i % side == 0)
			printf("\n");
		printf("%3d ", num[i]);
	}
}
int main()
{
	int begin, end, num[900] = { 0 }, key = 0;
	begin = time(NULL);
	for (int i = 0; i < side * side; i++)
	{
		num[i] = i + 1;
	}
	while (key == 0)
	{
		wash(num);
		key = judge(num);
	}
	printf("right:\n");
	show(num);
	end = time(NULL);
	printf("\n用时%ds", end - begin);

}