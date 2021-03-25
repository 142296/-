#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void hui(char p[28][100])
{
	int club = 0, i, j;
	float  sum1 = 0.0, sum2 = 0.0, b1 = 0.0, b2 = 0.0;
	float a = 0, b = 0.0;
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if ((p[2 * i][j]) == '*')
			{
				sum1 += i + 1;
				sum2 += (99 - j);
			}
		}
	}
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 100; j++) {
			if ((p[2 * i][j]) == '*')
			{
				b1 += ((i + 1) - 1.0 * sum1 / 14) * ((100 - j) - 1.0 * sum2 / 14);
				b2 += (i + 1 - 1.0 * sum1 / 14) * (i + 1 - 1.0 * sum1 / 14);
			}
		}
	}
	b = 1.0 * b1 / b2;
	a = (1.0 * sum2 / 14) - (1.0 * b * sum1 / 14);
	printf("线性回归方程\na=%f b=%f\n", a, b);
	printf("y=%fx+%f", b, a);
}
int main()
{
	double date1[14], date2[14], date3[14];
	int L, select, i, j, k, l, max = -1, min = 999999, average1, average2;
	double max1 = -1.00, min1 = 9999.0, average3, j1 = 0, k1 = 0, l1 = 0;
	long int k2 = 0, j2 = 0;
	int PEP_DATA[][3] = { 2014,3,1, 2006,11,1,2007,2,1,2007,2,1,2008,8,1,2009,4,1,2008,2,1,2006,3,1,2010,4,1,2011,6,1,2010,7,1,2010,11,1,2004,11,1,2006,11,1,2006,10,1, }; //年月日
	int c[3];																																							//存差值
	int cishu[14] = { 210,140,135,23,152,92,101,73,56,64,43,145,29,118 };  //乘坐飞行次数
	int li[14] = { 580717,293678,283712,281336,309928,294585,287042,287230,321489,375074,262013,271438,321529,179514 };//累计飞行里程
	double discount[14] = { 0.961639043,1.25231444,1.254675516,1.090869565,0.970657895,0.967692483,0.965346535,0.962070222,0.828478237,0.708010153,0.988658044,0.95253487,0.799126984,1.398381742 };//折扣
	char tu1[29][100] = { 0 };
	char tu2[29][100] = { 0 };
	char tu3[29][100] = { 0 };
r:	tu1[29][100] = { 0 };
	tu2[29][100] = { 0 };
	tu3[29][100] = { 0 };
	for (i = 0, j = 0, k = 0, j1 = 0; i < 14; i++)
	{
		j += cishu[i];
		k += li[i];
		j1 += discount[i];
	}average1 = j / 14;
	average2 = k / 14;
	average3 = j1 / 14.0;
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t\t\t*   航空公司客服系统   *\n");
	printf("\t\t\t\t1.计算会员入会时间距离观测窗口结束的月数\n");
	printf("\t\t\t\t2.乘坐飞机次数最大值和最小值\n");
	printf("\t\t\t\t3.累计飞行里程最大值和最小值\n");
	printf("\t\t\t\t4.飞机折扣的最大值和最小值\n");
	printf("\t\t\t\t5.乘坐飞机次数的平均值\n");
	printf("\t\t\t\t6.累计飞行里程的平均值\n");
	printf("\t\t\t\t7.飞机折扣的平均值\n");
	printf("\t\t\t\t8.各个参数的方差\n");
	printf("\t\t\t\t9.画柱形图.\n");
	printf("\t\t\t\t10.画折线图（我可能画出了散点图).\n");
	printf("\t\t\t\t请选择[数字]");
	scanf_s("%d", &select);
	getchar();
	system("cls");
	switch (select)
	{
	case 1:
		printf("\n\n\n\n");
		for (i = 1; i < sizeof PEP_DATA / sizeof PEP_DATA[0]; i++)
		{
			for (j = 0; j < 3; j++)
			{
				c[j] = (int)(PEP_DATA[0][j] - PEP_DATA[i][j]);
			}
			L = c[0] * 12 + c[1];
			printf("\t\t\t\t%-2d号会员入会时间距离观测窗口结束的月数=%d\n", i, L);
		}
		break;
	case 2:
		for (i = 0; i < 14; i++)
		{
			if (cishu[i] > max)
			{
				j = i;
				max = cishu[i];
			}
			if (cishu[i] < min)
			{
				k = i;
				min = cishu[i];
			}
		}
		printf("\n\n\n\n\n\n\t\t\t\t乘坐飞机次数最大是%-2d号为%d,最小是%-2d号=%d\n", j + 1, max, k + 1, min);
		break;
	case 3:
		for (i = 0; i < 14; i++)
		{
			if (li[i] > max)
			{
				j = i;
				max = li[i];
			}
			if (li[i] < min)
			{
				k = i;
				min = li[i];
			}
		}
		printf("\n\n\n\n\n\n\n\t\t\t\t飞行里程最大是%-2d号为%d,最小是%-2d号=%d\n", j + 1, max, k + 1, min);
		break;
	case 4:
		for (i = 0; i < 14; i++)
		{
			if (discount[i] > max1)
			{
				j = i;
				max1 = discount[i];
			}
			if (discount[i] < min1)
			{
				k = i;
				min1 = discount[i];
			}
		}
		printf("\n\n\n\n\n\n\n\t\t\t\t折扣最大是%d是号为%f,最小是%d号是%f\n", j + 1, max1, k + 1, min1);
		break;
	case 5:
	l:system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t乘坐飞机次数的平均值=%d\n", average1 = j / 14);
		printf("\t\t\t\t输入'h'获得高于平均值,'d'获得低于平均值");
		k = getchar();
		if (k == 'h')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (cishu[i] > average1)
				{
					k = i;
					printf("\t\t\t\t\t%d号:%d\n", k + 1, cishu[k]);
				}
			}
		}
		if (k == 'd')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++)
			{
				if (cishu[i] < average1)
				{
					k = i;
					printf("\t\t\t\t\t%d号:%d\n", k + 1, cishu[k]);
				}
			}

		}
		getchar();
		printf("\t\t\t\t\t输入'l'返回上一页，'r'返回主页,任意键退出");
		k = getchar();
		getchar();
		if (k == 'l')
			goto l;
		if (k == 'r')
			goto r1;
		break;
	case 6:
	m:system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t乘坐飞机里程的平均值=%d\n", average2);
		printf("\t\t\t\t输入'h'获得高于平均值,'d'获得低于平均值");
		k = getchar();
		if (k == 'h')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (li[i] > average2)
				{
					k = i;
					printf("\t\t\t\t\t%d号:%d\n", k + 1, li[k]);
				}
			}
		}
		if (k == 'd')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (li[i] < average2)
				{
					k = i;
					printf("\t\t\t\t\t%d号:%d\n", k + 1, li[k]);
				}
			}
		}
		getchar();
		printf("\t\t\t\t\t输入'l'返回上一页,r返回主页,任意键退出");
		k = getchar();
		getchar();
		if (k == 'l')
			goto m;
		if (k == 'r')
			goto r1;
		break;
	case 7:
	n:system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t折扣的平均值=%f\n", average3);
		printf("\t\t\t\t输入'h'获得高于平均值,'d'获得低于平均值");
		k = getchar();
		if (k == 'h')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (discount[i] > average3)
				{
					k = i;
					printf("\t\t\t\t\t%d号:%f\n", k + 1, discount[k]);
				}
			}
		}
		if (k == 'd')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (discount[i] < average3)
				{
					k = i;
					printf("\t\t\t\t\t%d号:%f\n", k + 1, discount[k]);
				}
			}
		}
		getchar();
		printf("\t\t\t\t\t输入'l'返回上一页,r返回主页,任意键退出\n");
		k = getchar();
		getchar();
		if (k == 'l')
			goto n;
		if (k == 'r')
			goto r1;
		break;
	case 8:
		for (i = 0, j = 0, k = 0, j1 = 0; i < 14; i++)
		{
			j2 += (long int)pow(cishu[i] - average1, 2);
			k2 += (long int)pow(li[i] - average2, 2);
			j1 += pow(discount[i] - average3, 2);
		}
		l1 = sqrt(j2 / 14.0);
		k1 = sqrt(k2 / 14.0);
		j1 = sqrt(j1 / 14.0);
		printf("\n\n\n\n\n\n\n\t\t\t\t标准差:次数:%f里程:%f折扣:%f\n", l1, k1, j1);
		printf("标准化数据:\t次数\t\t里程 \t\t折扣\n");
		for (i = 0; i < 14; i++)
		{
			date1[i] = ((double)(cishu[i] - average1)) / l1;
			date2[i] = ((double)(li[i] - average2)) / k1;
			date3[i] = ((double)(discount[i] - average3)) / j1;
			printf("%2d号:", i + 1);
			printf("\t\t%8f\t %8f\t %8f\n", date1[i], date2[i], date3[i]);
		}
		//printf("\n");
		break;
	case 9:
		for (i = 0; i < 14; i++)
		{
			for (j = 99; j >= 99 - cishu[i] / 10; j--)
			{
				tu1[2 * i][j] = '*';
			}
			for (k = 99; k >= 99 - li[i] / 10000; k--)
			{
				tu2[2 * i][k] = '*';
			}
			for (l = 99; l >= 99 - discount[i] * 60; l--)
			{
				tu3[2 * i][l] = '*';
			}
		}
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t输入'1=次数图,2=里程图,3=折扣图");
		switch (getchar())
		{
		case '1':system("cls");
			for (i = 0; i < 100; i++)
			{
				printf("\t%-2d", 100 - i);
				for (j = 0; j < 29; j++)
				{
					printf("%c", tu1[j][i]);
				}printf("\n");
			}
			printf("\t0 1 2 3 4 5 6 7 8 9 1011121314\n");
			break;
		case '2':
			system("cls");
			for (i = 0; i < 100; i++)
			{
				printf("\t%-2d", 100 - i);
				for (j = 0; j < 29; j++)
				{
					printf("%c", tu2[j][i]);
				}printf("\n");
			}	printf("\t0 1 2 3 4 5 6 7 8 9 1011121314\n");
			break;
		case '3':
			system("cls");
			for (i = 0; i < 100; i++)
			{
				printf("\t%-2d", 100 - i);
				for (j = 0; j < 29; j++)
				{
					printf("%c", tu3[j][i]);
				}
				printf("\n");
			}
			printf("\t0 1 2 3 4 5 6 7 8 9 1011121314\n");
			fflush(stdin);
			break;
		}
		getchar();
		break;
	case 10:
		for (i = 0; i < 14; i++)
		{
			j = 99 - cishu[i] / 10;
			tu1[2 * i][j] = '*';

			k = 99 - li[i] / 10000;
			tu2[2 * i][k] = '*';
			l = discount[i] * 60;
			tu3[2 * i][l] = '*';
		}
		printf("\t\t\t\t\t输入1=次数图,2=里程图,3=折扣图");
		switch (getchar())
		{
		case '1':
			system("cls");
			for (i = 0; i < 100; i++)
			{
				printf("\t%-2d", 100 - i);
				for (j = 0; j < 29; j++)
				{
					printf("%c", tu1[j][i]);
				}printf("\n");
			}
			printf("\t0 1 2 3 4 5 6 7 8 9 1011121314\n");
			printf("这么规整的散点图，求个线性回归方程吧0.0\n");
			getchar();
			getchar();
			hui(tu1);
			break;
		case '2':
			system("cls");
			for (i = 0; i < 100; i++)
			{
				printf("\t%-2d", 100 - i);
				for (j = 0; j < 29; j++)
				{
					printf("%c", tu2[j][i]);
				}printf("\n");
			}	printf("\t0 1 2 3 4 5 6 7 8 9 1011121314\n");
			break;
		case '3':
			system("cls");
			for (i = 0; i < 100; i++)
			{
				printf("\t%-2d", 100 - i);
				for (j = 0; j < 29; j++)
				{
					printf("%c", tu3[j][i]);
				}
				printf("\n");
			}	printf("\t0 1 2 3 4 5 6 7 8 9 1011121314\n");
			break;
		}
		getchar();
		break;
	default: printf("\n\n\n\n\t\t\t\t\t\terror\n");
		break;
	}
	fflush(stdin);
	printf("\t\t\t\t\t输入'r'返回主页,任意键退出");
	k = getchar();
r1:if (k == 'r')
goto r;
else
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t再见!");
}
getchar();
}