#include<stdio.h>								//排列组合方法解决
#include<stdlib.h>
int Count = 0;
void Row_combination(int i, int n, int k, int o, int row_sort[])
{
	for (int j = i + 1; j <= n - k + o && o < k; j++)
	{
		row_sort[o] = j;
		Row_combination(j, n, k, o + 1, row_sort);
		if (o == k - 1)
		{
			for (int l = 0; l < k; l++)
			{
				printf("%d", row_sort[l] + 1);
			}
			printf("\n");
		}
	}
}
int factorial(int a)
{
	int mul = 1;
	while (a != 0)
		mul *= a--;
	return mul;
}
int Cnm(int n, int m)
{
	return factorial(n) / factorial(n - m) / factorial(m);
}
int check(int chesser_board[], int line, int row, int n)
{
	if (chesser_board[n * line + row] == '.')    //判断空白与否
		return 0;
	for (int i = 0; i < n; i++)         //判断列
	{
		if (chesser_board[i * n + row] == 1 && i != line)
			return 0;
	}
	for (int i = 0; i < n; i++)             //判断行
	{
		if (chesser_board[n * line + i] == 1 && i != row)
			return 0;
	}
	return 1;
}
void show(int chesser_board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			printf("%c", chesser_board[i][j]);
		printf("\n");
	}
}
int main()
{
	int n, k, chesser_board[8][8] = {}, length = 0, row_combination = 0, * array;
	while (scanf_s("%d%d", &n, &k) && n != -1 && k != -1)
	{
		getchar();
		array = (int*)malloc(4 * k);	
		printf("%d种\n", Cnm(n, k));				//总情况数	
		Row_combination(-1, n, k, 0, array);		//列出所有情况
		Count = 0;
	}
}