#include<stdio.h>
int main()
{
	while (1)
	{
		int a;
		unsigned mask = 1 << 31;
		scanf_s("%d", &a);						 //��32λΪ����λ����1&�ɵ�������
		for (; mask; mask >>= 1)
		{
			printf("%d", a & mask ? 1 : 0);
		}
		printf("\n");
	}
}