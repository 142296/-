#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
int i, j;
typedef struct Student {
	int ID;
	float EScore;
	float MScore;
}St;
void output(St sheet[], int n);      //输出成绩
int input(St sheet[], int n);		//输入保存成绩
void sort(St sheet[], int n);		//排序
void swap(float* p, float* q);      //交换成绩

void swap(float* p, float* q)
{
	float t = *p; *p = *q; *q = t;
}
int input(St sheet[])
{
	int n;
	printf("成绩输入：\n请输入人数(n<%d)\n", N);
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		printf("请输入学号");
		scanf_s("%d", &sheet[i].ID);
		getchar();
		printf("请输入数学成绩");
		scanf_s("%f", &sheet[i].MScore);											//接受成绩
		getchar();
		printf("请输入英语成绩");
		scanf_s("%f", &sheet[i].EScore);											//接受成绩
		getchar();
	}
	return n;
}
void sort(St sheet[], int n, char subject)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			switch (subject)
			{
			case 'E':if (sheet[j].EScore < sheet[j + 1].EScore) break; else continue;
			case 'M':if (sheet[j].MScore < sheet[j + 1].MScore) break; else continue;
			case 'A':if (sheet[j].EScore + sheet[j].MScore < sheet[j + 1].EScore + sheet[j + 1].MScore)
				break;
					else continue;
			case 'I':if (sheet[j].ID > sheet[j + 1].ID) break; else continue;
			}
			swap(&sheet[j].EScore, &sheet[j + 1].EScore);
			swap(&sheet[j].MScore, &sheet[j + 1].MScore);
			sheet[j].ID ^= sheet[j + 1].ID;
			sheet[j + 1].ID ^= sheet[j].ID;
			sheet[j].ID ^= sheet[j + 1].ID;
		}
	}
	output(sheet, n);
}
void output(St sheet[], int n)
{
	printf("学号\t数学\t英语\n");
	for (i = 0; i < n; i++)
		printf("%d:\t%.2f\t%.2f\n", sheet[i].ID, sheet[i].MScore, sheet[i].EScore);
}
int main()
{
	St sheet[N];
	char r;
	int a, b, n = 0;
	for (r = 'r'; r == 'r' || r == 'R';)
	{
		printf("学生成绩管理系统\n\n");
		printf("****************************************\n");
		printf("*               主菜单                 *\n");
		printf("****************************************\n\n");
		printf("  1:成绩输入\t\t2：显示成绩\n");
		printf("  3:成绩排序\t\t4：退出系统\n");
		printf("请输入数字");
		scanf_s("%d", &a);
		system("cls");
		getchar();
		switch (a)
		{
		case 1:n = input(sheet); break;
		case 2:output(sheet, n); break;
		case 3:printf("1.英语成绩排序\n2.数学成绩排序\n3.总成绩排序\n4.学号排序\n请输入数字");
			scanf_s("%d", &b);
			getchar();
			switch (b)
			{
			case 1:sort(sheet, n, 'E'); break;
			case 2:sort(sheet, n, 'M'); break;
			case 3:sort(sheet, n, 'A'); break;
			case 4:sort(sheet, n, 'I'); break;
			}break;
		case 4:printf("退出系统:\n");
			printf("再见");
			goto end;
		default:printf("请输入有效字符");
		}
		printf("\n输入r返回主页");
		r = getchar();
		system("cls");
	}
end:return 0;
}