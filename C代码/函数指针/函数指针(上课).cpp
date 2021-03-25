#include<stdio.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int add(int a, int b)
{
	return a + b;
}
int result(int a, int b, int (*p)(int a, int b))
{
	int d = (*p)(a, b);
	return d;
}
int main()
{
	int a, b;
	a = 5, b = 10;
	printf("%d", result(a, b, max));
}