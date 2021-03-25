#include<stdio.h>    //杨辉三角形
#define size 20
int main()
{
	int a[size][size] = { 0 };
	for (int i = 0; i < size; i++)
	{
		a[i][0] = 1;     //初末值赋1
		a[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1]; //中间值依次等于上一行相加
		}
	}
	for (int i = 0; i < size; i++)   //输出
	{
		for (int j = 0; j <= i; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}