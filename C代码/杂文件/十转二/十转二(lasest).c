#include<stdio.h>
int main()
{
	while (1)
	{
		int a;
		unsigned mask = 1 << 31;
		scanf_s("%d", &a);						 //第32位为符号位。与1&可得正负。
		for (; mask; mask >>= 1)
		{
			printf("%d", a & mask ? 1 : 0);
		}
		printf("\n");
	}
}