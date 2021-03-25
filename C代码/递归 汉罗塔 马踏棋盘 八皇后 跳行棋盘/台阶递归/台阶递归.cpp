#include<stdio.h>
int Count = 0;
void pace(int n, int size)
{
	if (n == 0)
	{
		Count++;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (3 * i + 1 <= n)
		{
			n -= (3 * i + 1);
			pace(n, size);
			n += (3 * i + 1);
		}
		else
			return;
	}
}
int main()
{
	int i, n;
	scanf_s("%d", &n);
	for (i = 0; 3 * i + 1 <= n; i++);		//获取数组长度
	pace(n, i);
	printf("%d\n", Count % 100003);
}