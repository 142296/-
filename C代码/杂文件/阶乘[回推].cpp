#include<stdio.h>
int f(int a)
{
	int sum;
	if (a > 0)
		sum = a *f(a-1);
	else
	{
		sum = 1;
	}
	return sum;
}
int main()
{
	int a,b;
	scanf_s("%d", &a);
	b=f(a);
	printf("%d", b);
}