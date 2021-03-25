#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define side 6

int pace(int chess[side][side], int line, int row);             //走一步
void show(int chess[side][side]);									//输出
int check(int chess[side][side]);								//检查

int pace(int chess[side][side], int line, int row)
{

	int tem[side][side] = { 0 };
	int key = 0;
	for (int i = 0; i < side; i++)                                //保存该棋盘
	{
		for (int j = 0; j < side; j++)
		{
			tem[i][j] = chess[i][j];
		}
	}
	chess[line][row] = 1;
	if (line - 1 >= 0 && row - 2 >= 0 && chess[line - 1][row - 2] != 1)  //上1左2
		key = pace(chess, line - 1, row - 2);
	if (line - 2 >= 0 && row - 1 >= 0 && chess[line - 2][row - 1] != 1)  //上2左1
		key = pace(chess, line - 2, row - 1);
	if (line - 2 >= 0 && row + 1 < side && chess[line - 2][row + 1] != 1)  //上2右1
		key = pace(chess, line - 2, row + 1);
	if (line - 1 >= 0 && row + 2 < side && chess[line - 1][row + 2] != 1)  //上1右2
		key = pace(chess, line - 1, row + 2);
	if (line + 1 < side && row + 2 < side && chess[line + 1][row + 2] != 1)  //下1右2
		key = pace(chess, line + 1, row + 2);
	if (line + 2 < side && row + 1 < side && chess[line + 2][row + 1] != 1)  //下2右1
		key = pace(chess, line + 2, row + 1);
	if (line + 2 < side && row - 1 >= 0 && chess[line + 2][row - 1] != 1)  //下2左1
		key = pace(chess, line + 2, row - 1);
	if (line + 1 < side && row - 2 >= 0 && chess[line + 1][row - 2] != 1)  //下1左2
		key = pace(chess, line + 1, row - 2);
	if (check(chess)&&key!=1)											//当无路可走时判断 
		key = 1;
	if (key)										//如果满了，则输出
	{
		int t = time(NULL);
		while (time(NULL) <= t);
		system("cls");
		show(tem);
	}
	else
		chess[line][row] = 0;                                       //不符合则逐项归零
	return key;										//如果满了，chess一直是满的

}
void show(int chess[side][side])
{
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if (chess[i][j])										//因为是逆序输出，所以1为空
				printf("□");
			else
				printf("■");
		}
		printf("\n");
	}

}
int check(int chess[side][side])
{
	int key = 1;
	for (int i = 0;key!=0&&i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if (chess[i][j] == 0)
			{
				key = 0;
				break;
			}
		}
	}
	return key;
}

int main()
{
	for (int i = 0; i < side; i++)                     //第i行
		for (int j = 0; j < side; j++)					//第j列
		{
			int chess[side][side] = { 0 };
			pace(chess, i, j);
			printf("完成i=%dj=%d", i, j);
			printf("\n\n");
		}
}