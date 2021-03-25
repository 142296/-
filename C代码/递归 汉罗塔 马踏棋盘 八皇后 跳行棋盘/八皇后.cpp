#include<stdio.h>
#define side 7
int count = 0;

int check(int chess[][side], int, int);
void set(int, int chess[][side]);
void out(int chess[][side]);                    //输出棋盘

int check(int chess[][side], int i, int j)
{
	int k, l;
	for (l = 0; l < side; l++) {                       //判断行
		if (chess[i][l] && l != j) {
			return 0;
		}
	}
	for (l = 0; l < side; l++)                                 //判断列
	{
		if (chess[l][j] && l != i)
		{
			return 0;
		}
	}
	for (k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--)                //判断左上角
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	for (k = i - 1, l = j + 1; k >= 0 && l < side; k--, l++)                //判断右上角
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	for (k = i + 1, l = j - 1; k < side && l >= 0; k++, l--)                //判断左下角
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	for (k = i + 1, l = j + 1; k < side && l < side; k++, l++)					//判断右下角
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	return 1;
}
void set(int line, int chess[][side])
{
	int row;
	if (line == side)                              //到达足够的深度（行数）
	{
		out(chess);									//输出
	}
	for (row = 0; row < side; row++)                //在该行某一列放女王
	{
		if (check(chess, line, row))				//判断放置的可行性
		{
			chess[line][row] = 1;
			set(line + 1, chess);
			//放置失败或放置完成
			//一层一层重置整个棋盘
			chess[line][row] = 0;
		}
	}
}
void out(int chess[][side])
{
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if (chess[i][j])
				printf("■");
			else
				printf("□");
		}
		printf("\n");
	}
	printf("\n");
	count++;
}
int main()
{
	int chess[side][side] = { 0 };
	set(0, chess);
	printf("%d", count);
}