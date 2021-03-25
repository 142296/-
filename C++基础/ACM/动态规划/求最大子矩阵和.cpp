#include<bits/stdc++.h>
using namespace std;
int num[503][503];
int n, m;
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%d", &num[i][j]);
	//求前缀表
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			num[i][j] += num[i - 1][j];
		}
	}
	int temp = 0;
	int max = -pow(2, 30);
	for (int i = 0; i < n; i++)	//行起始
	{
		for (int j = i; j < n; j++)	//行末
		{
			temp = 0;
			for (int k = 0; k < m; k++)	//第k行
			{
				if (i - 1 < 0)
					temp += num[j][k];
				else 
					temp += num[j][k] - num[i - 1][k];//第k列第i到j行
				if (temp < 0)
					temp = 0;
				if (temp > max)
					max = temp;

			}
		}
	}
	printf("%d\n", max);
}