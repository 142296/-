#include<stdio.h>
void Hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("%c-->%c\n", x, y);
		printf("%c-->%c\n", y, z);
	}
	else {
		Hanoi(n - 1, x, y, z);
		printf("%c-->%c\n", x, y);
		Hanoi(n - 1, z, y, x);
		printf("%c-->%c\n", y, z);
		Hanoi(n - 1, x, y, z);
	}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	Hanoi(n, 'x', 'y', 'z');
}