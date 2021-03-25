#include<stdio.h>
#define size 3
int main()
{
	int a[size][size];
	int mul[2 * size];
	int sum = 0;
	for (int i = 0; i < 2 * size; i++)
		mul[i] = 1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf_s("%d", &a[i][j]);
	for (int num = 0; num < 2 * size; num++)
	{
		for (int i = 0; i < size; i++)
		{
			if (num < size)
				mul[num] *= a[i][(i + num) % size];
			else
				mul[num] *= a[(i + num) % size][size - i - 1];
		}
	}
	for (int i = 0; i < 2 * size; i++)
	{
		if (i < size)
			sum += mul[i];
		else
			sum -= mul[i];
	}
	printf("%d", sum);
}