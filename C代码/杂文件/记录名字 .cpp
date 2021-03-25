#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i, j, max, min;
	char n[3][10] = { 0 };								//定义一个大小为3个10的数组储存名字
	int g[3];										//定义大小为3个的数组储存成绩
	for (i = 0; i < 3; i++)
	{
		printf("请输入名字");
		for (j = 0; j < 10; j++)								//记录名字
		{
			n[i][j] = getchar();								//接受名字
			if (n[i][j] == '\n')									//如果接收到“回车”，跳出循环
				break;
		}
		printf("请输入成绩");
		scanf_s("%d", &g[i]);											//接受成绩
		getchar();
	}
	for (i = 0, j = 0; i < 3; i++)
	{
		j = 0;
		while (n[i][j] != '\n')
		{
			printf("%c", n[i][j]);										//输出成绩
			j++;
		}
		printf("同学%d分\n", g[i]);										//输出分数
	}
	max = min = g[0];
	for (i = 1; i < 3; i++)								//遍历数组
	{
		if (g[i] > max)									//求最大值
			max = g[i];
		if (g[i] < min)								//求最小值
			min = g[i];
	}
	printf("max=%d min=%d", max, min);
}