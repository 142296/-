#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int*p[2],(*q)[4];
	p[0] = (int*)malloc(4 * sizeof(int));
	p[1] = (int*)malloc(4 * sizeof(int));
	int a[2][4];
	q = a;
}
