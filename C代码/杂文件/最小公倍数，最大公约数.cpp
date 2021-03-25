#include<stdio.h>
void swap(int* p, int* q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}
int da(int a, int b)
{
	int temp;
	do {
		temp = a % b;
		a = b;
		b = temp;
	} while (temp != 0);
	return a;
}
int xiao(int a, int b)
{
	return a * b / da(a, b);
}
int main()
{
	int a, b, c, d;
	scanf_s("%d %d", &a, &b);
	if (a < b)
		swap(&a, &b);
	c = da(a, b);
	d = xiao(a, b);
	printf("%d\n%d", c, d);
}