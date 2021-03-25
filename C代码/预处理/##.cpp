#include<stdio.h>
#define x(n) x##n
#define y(x)  printf("as"#x"ds");
int main()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		int x(i) = i;
		printf("%d\n", x(i));
	}
	y(4);
}