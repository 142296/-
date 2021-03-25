#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int* p, int* q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}
int main(void)
{
	int a, i, j, c;
	char r;
	char n[3][10];
	char m[10];
	int g[3], max, min;
	for (r = 'r'; r == 'r';)
	{
		printf("学生成绩管理系统\n\n");
		printf("****************************************\n");
		printf("*               主菜单                 *\n");
		printf("****************************************\n\n");
		printf("  1:成绩输入\t\t2：成绩删除\n");
		printf("  3:成绩查询\t\t4：成绩排序\n");
		printf("  5:最高低分\t\t6：统计平均分\n");
		printf("  7:显示成绩\t\t8：退出系统\n");
		printf("请输入数字");
		scanf_s("%d", &a);
		system("cls");
		getchar();
		switch (a)
		{
		case 1:
			printf("成绩输入：\n");
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
			break;
		case 2:
			printf("成绩删除：\n");
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
			printf("请输入想要删除的同学成绩");
			gets_s(m);
			system("cls");
			for (i = 0; i < 3; i++)
			{
				c = 0;
				for (j = 0; j < 10; j++)
				{
					if (n[i][j] == '\n')
						break;
					if (n[i][j] != m[j])
						c = 1;
				}
				if (c)
				{
					for (j = 0; j < 10; j++)
					{
						if (n[i][j] == '\n')
							break;
						printf("%c", n[i][j]);
					}
					printf("同学%d分\n", g[i]);
				}
			}
			break;
		case 3:
			printf("成绩查询：\n");
			printf("请输入想要查找的同学成绩");
			gets_s(m);
			system("cls");
			for (i = 0; i < 3; i++)
			{
				c = 1;
				for (j = 0; j < 10; j++)
				{
					if (n[i][j] == '\n')
						break;
					if (n[i][j] != m[j])
						c = 0;
				}
				if (c)
				{
					for (j = 0; j < 10; j++)
					{
						if (n[i][j] == '\n')
							break;
						printf("%c", n[i][j]);
					}
					printf("同学%d分\n", g[i]);
				}
			}
			break;
		case 4:printf("成绩排序:\n");
			for (i = 0; i < 3; i++)
			{
				for (j = 2; j >= i; j--)
				{
					if (g[i] < g[j])
						swap(&g[i], &g[j]);
				}
			}
			for (i = 0; i < 3; i++)
				printf("%d ", g[i]);
			break;
		case 5:printf("最大小值:\n");
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
			break;
		case 6:printf("平均分:\n");
			printf("平均分=%.4f", (g[1] + g[2] + g[0]) / 3.0);		//输出平均分
			break;
		case 7:printf("展示成绩:\n");
			for (i = 0, j = 0; i < 3; i++)
			{
				j = 0;
				while (n[i][j] != '\n')
				{
					printf("%c", n[i][j]);										//输出成绩
					j++;
				}
				printf("同学%d分\n", g[i]);		//输出分数
			}break;
		case 8:printf("退出系统:\n");
			printf("再见");
			goto end;

		}
		printf("输入r回到主页");
		r = getchar();
		system("cls");
	}
end:	return 0;
}