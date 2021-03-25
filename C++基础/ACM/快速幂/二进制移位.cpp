#include<stdio.h>				//二进制移位
int fun(int k, int n, int a)    //计算 (a^k)%n  
{
	if (k / 2)
	{
		int temp = a;
		a = fun(k >> 1, n, a);
		a = a * a % n;
		if (k % 2)
		{
			a = a * temp % n;
		}
	}
	return a;
}
int main()
{
	int k, n;
	long long int a;
	scanf_s("%d%d%d", &a, &k, &n);
	a = fun(k, n, a);
	printf("%d", a);
}