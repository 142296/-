#include<stdio.h>
#define x(n) x##n
#define PRINT(n)  printf("x"#n"=%d\n",x##n);
int main()
{
	int x(1) = 1, x(2) = 2, x(3) = 3;
	PRINT(1);
	PRINT(2);
	PRINT(3);
}