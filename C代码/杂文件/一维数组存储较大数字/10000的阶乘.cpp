#include<stdio.h>
int main()
{
	while (1)
	{
		long long j[4000] = { j[0] = 1 };
		int num, i, end = 0;
		char flag = 0;
		scanf_s("%d", &i);
		while (i)
		{
			for (num = 0; num < 4000; num++)
			{
				j[num] *= i;
			}
			for (num = 0; num < 4000; num++)
			{
				if (j[num] > 1000000000)
				{
					j[num + 1] = j[num + 1] + (j[num] / 1000000000);
					j[num] %= 1000000000;
					if (num >= end)
						end = num + 1;
				}
			}
			i--;
		}
		while (end >= 0)
		{
			if (j[end] == 0)
			{
				printf("%09d", 0);
			}
			else
				printf("%09ld", j[end]);
			end--;

		}
	}
}