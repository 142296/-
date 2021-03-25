#include<stdio.h>
#include<math.h>
#define jinzhi 2		//用jinzhi 来算，各进制同理
int fun(int k, int n, int a)    //计算 (a^k)%n  log 2(n) 复杂度
{
	if (k / jinzhi)
	{
		int temp = a;
		a = fun(k / jinzhi, n, a);
		a = int(pow(a, jinzhi)) % n;
		a = int(a * pow(temp, k % jinzhi)) % n;
	}
	else if (k % jinzhi)
	{
		a = int(a * pow(a, k % jinzhi - 1)) % n;
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