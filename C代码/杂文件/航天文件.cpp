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
	printf("���Իع鷽��\na=%f b=%f\n", a, b);
	printf("y=%fx+%f", b, a);
}
int main()
{
	double date1[14], date2[14], date3[14];
	int L, select, i, j, k, l, max = -1, min = 999999, average1, average2;
	double max1 = -1.00, min1 = 9999.0, average3, j1 = 0, k1 = 0, l1 = 0;
	long int k2 = 0, j2 = 0;
	int PEP_DATA[][3] = { 2014,3,1, 2006,11,1,2007,2,1,2007,2,1,2008,8,1,2009,4,1,2008,2,1,2006,3,1,2010,4,1,2011,6,1,2010,7,1,2010,11,1,2004,11,1,2006,11,1,2006,10,1, }; //������
	int c[3];																																							//���ֵ
	int cishu[14] = { 210,140,135,23,152,92,101,73,56,64,43,145,29,118 };  //�������д���
	int li[14] = { 580717,293678,283712,281336,309928,294585,287042,287230,321489,375074,262013,271438,321529,179514 };//�ۼƷ������
	double discount[14] = { 0.961639043,1.25231444,1.254675516,1.090869565,0.970657895,0.967692483,0.965346535,0.962070222,0.828478237,0.708010153,0.988658044,0.95253487,0.799126984,1.398381742 };//�ۿ�
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
	printf("\n\n\n\n\n\n\t\t\t\t\t*   ���չ�˾�ͷ�ϵͳ   *\n");
	printf("\t\t\t\t1.�����Ա���ʱ�����۲ⴰ�ڽ���������\n");
	printf("\t\t\t\t2.�����ɻ��������ֵ����Сֵ\n");
	printf("\t\t\t\t3.�ۼƷ���������ֵ����Сֵ\n");
	printf("\t\t\t\t4.�ɻ��ۿ۵����ֵ����Сֵ\n");
	printf("\t\t\t\t5.�����ɻ�������ƽ��ֵ\n");
	printf("\t\t\t\t6.�ۼƷ�����̵�ƽ��ֵ\n");
	printf("\t\t\t\t7.�ɻ��ۿ۵�ƽ��ֵ\n");
	printf("\t\t\t\t8.���������ķ���\n");
	printf("\t\t\t\t9.������ͼ.\n");
	printf("\t\t\t\t10.������ͼ���ҿ��ܻ�����ɢ��ͼ).\n");
	printf("\t\t\t\t��ѡ��[����]");
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
			printf("\t\t\t\t%-2d�Ż�Ա���ʱ�����۲ⴰ�ڽ���������=%d\n", i, L);
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
		printf("\n\n\n\n\n\n\t\t\t\t�����ɻ����������%-2d��Ϊ%d,��С��%-2d��=%d\n", j + 1, max, k + 1, min);
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
		printf("\n\n\n\n\n\n\n\t\t\t\t������������%-2d��Ϊ%d,��С��%-2d��=%d\n", j + 1, max, k + 1, min);
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
		printf("\n\n\n\n\n\n\n\t\t\t\t�ۿ������%d�Ǻ�Ϊ%f,��С��%d����%f\n", j + 1, max1, k + 1, min1);
		break;
	case 5:
	l:system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t�����ɻ�������ƽ��ֵ=%d\n", average1 = j / 14);
		printf("\t\t\t\t����'h'��ø���ƽ��ֵ,'d'��õ���ƽ��ֵ");
		k = getchar();
		if (k == 'h')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (cishu[i] > average1)
				{
					k = i;
					printf("\t\t\t\t\t%d��:%d\n", k + 1, cishu[k]);
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
					printf("\t\t\t\t\t%d��:%d\n", k + 1, cishu[k]);
				}
			}

		}
		getchar();
		printf("\t\t\t\t\t����'l'������һҳ��'r'������ҳ,������˳�");
		k = getchar();
		getchar();
		if (k == 'l')
			goto l;
		if (k == 'r')
			goto r1;
		break;
	case 6:
	m:system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t�����ɻ���̵�ƽ��ֵ=%d\n", average2);
		printf("\t\t\t\t����'h'��ø���ƽ��ֵ,'d'��õ���ƽ��ֵ");
		k = getchar();
		if (k == 'h')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (li[i] > average2)
				{
					k = i;
					printf("\t\t\t\t\t%d��:%d\n", k + 1, li[k]);
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
					printf("\t\t\t\t\t%d��:%d\n", k + 1, li[k]);
				}
			}
		}
		getchar();
		printf("\t\t\t\t\t����'l'������һҳ,r������ҳ,������˳�");
		k = getchar();
		getchar();
		if (k == 'l')
			goto m;
		if (k == 'r')
			goto r1;
		break;
	case 7:
	n:system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t�ۿ۵�ƽ��ֵ=%f\n", average3);
		printf("\t\t\t\t����'h'��ø���ƽ��ֵ,'d'��õ���ƽ��ֵ");
		k = getchar();
		if (k == 'h')
		{
			system("cls");
			printf("\n\n\n\n");
			for (i = 0; i < 14; i++) {
				if (discount[i] > average3)
				{
					k = i;
					printf("\t\t\t\t\t%d��:%f\n", k + 1, discount[k]);
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
					printf("\t\t\t\t\t%d��:%f\n", k + 1, discount[k]);
				}
			}
		}
		getchar();
		printf("\t\t\t\t\t����'l'������һҳ,r������ҳ,������˳�\n");
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
		printf("\n\n\n\n\n\n\n\t\t\t\t��׼��:����:%f���:%f�ۿ�:%f\n", l1, k1, j1);
		printf("��׼������:\t����\t\t��� \t\t�ۿ�\n");
		for (i = 0; i < 14; i++)
		{
			date1[i] = ((double)(cishu[i] - average1)) / l1;
			date2[i] = ((double)(li[i] - average2)) / k1;
			date3[i] = ((double)(discount[i] - average3)) / j1;
			printf("%2d��:", i + 1);
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
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t����'1=����ͼ,2=���ͼ,3=�ۿ�ͼ");
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
		printf("\t\t\t\t\t����1=����ͼ,2=���ͼ,3=�ۿ�ͼ");
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
			printf("��ô������ɢ��ͼ��������Իع鷽�̰�0.0\n");
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
	printf("\t\t\t\t\t����'r'������ҳ,������˳�");
	k = getchar();
r1:if (k == 'r')
goto r;
else
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t�ټ�!");
}
getchar();
}