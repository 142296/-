#include<bits/stdc++.h>	//滑动窗口，
using namespace std;//给定一个含有 n 个正整数的数组和一个正整数 s ，
				//找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度
int main()
{
	srand(time(0));
	int a[20];
	int i, j;
	for (int i = 0; i < 20; i++)
		a[i] = rand() % 10;
	int sum, count = 20;
	cin >> sum;
	sum -= a[0];
	for (i = 0, j = 0; i < 20 || sum <= 0;)
	{
		if (sum > 0)
		{
			i++;
			if (i < 20);
			sum -= a[i];
		}
		if (sum <= 0)
		{
			if (i - j + 1 < count)
				count = i - j + 1;
			sum += a[j];
			j++;
		}
	}
	printf("%d", count);
}