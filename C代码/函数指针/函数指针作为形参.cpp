#include<stdio.h>
int add(int, int);
int sub(int, int);
int calc(int (*fp)(int, int), int, int);

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int calc(int (*fp)(int a, int b), int c, int d)
{
	return fp(c, d);
}
int main()
{
	printf("%d\n", calc(add, 3, 4));
	printf("%d", calc(sub, 5, 3));
}