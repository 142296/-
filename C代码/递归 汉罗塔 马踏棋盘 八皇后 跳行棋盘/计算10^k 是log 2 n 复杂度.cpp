#include<stdio.h>
int fun(int k, int n, int a)    //计算 (a^k)%n  log 2(n) 复杂度
{
	int i = 1;
	for (; i < k / 2; i *= 2)
		a = a * a % n;
	if (i == k)
		return a % n;
	return a * fun(k - i, n, a) % n;
}
int main()
{
	int k, n;
	long long int a;
	scanf_s("%d%d%d", &a, &k, &n);
	a = fun(k, n, a);
	printf("%d", a);
}