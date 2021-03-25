#include<stdio.h>
int main()
{
	int a = 20, b = 30;
	b = a ^ b;			//b=a^b
	a = a ^ b;			//a=a^(a^b)==b
	b = b ^ a;			//b=(a^b)^(a^a^b)==a^b^b == a
	printf("a=%d  b=%d", a, b);
}