#include<bits/stdc++.h>	//螺旋矩阵
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num[100][100] = { 0 };
	int i = 0, j = 0;
	int count = 1, cir = 1, cir1 = 1;
	while (count <= n * n)		//内部每个循环左闭右开
	{							//k计数，i,j记录坐标
		if (n - cir == 0)			//n为奇数，则最中心一个点赋值
			num[j][i] = count++;
		for (int k = 0; k < n - cir && count <= n * n; k++, i++)
			num[j][i] = count++;
		for (int k = 0; k < n - cir && count <= n * n; k++, j++)
			num[j][i] = count++;
		for (int k = 0; k < n - cir && count <= n * n; k++, i--)
			num[j][i] = count++;
		for (int k = 0; k < n - cir && count <= n * n; k++, j--)
			num[j][i] = count++;
		cir += 2;
		i++; j++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", num[i][j]);
		}
		printf("\n");
	}
}