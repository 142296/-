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
		printf("ѧ���ɼ�����ϵͳ\n\n");
		printf("****************************************\n");
		printf("*               ���˵�                 *\n");
		printf("****************************************\n\n");
		printf("  1:�ɼ�����\t\t2���ɼ�ɾ��\n");
		printf("  3:�ɼ���ѯ\t\t4���ɼ�����\n");
		printf("  5:��ߵͷ�\t\t6��ͳ��ƽ����\n");
		printf("  7:��ʾ�ɼ�\t\t8���˳�ϵͳ\n");
		printf("����������");
		scanf_s("%d", &a);
		system("cls");
		getchar();
		switch (a)
		{
		case 1:
			printf("�ɼ����룺\n");
			for (i = 0; i < 3; i++)
			{
				printf("����������");
				for (j = 0; j < 10; j++)								//��¼����
				{
					n[i][j] = getchar();								//��������
					if (n[i][j] == '\n')									//������յ����س���������ѭ��
						break;
				}
				printf("������ɼ�");
				scanf_s("%d", &g[i]);											//���ܳɼ�
				getchar();
			}
			break;
		case 2:
			printf("�ɼ�ɾ����\n");
			for (i = 0, j = 0; i < 3; i++)
			{
				j = 0;
				while (n[i][j] != '\n')
				{
					printf("%c", n[i][j]);										//����ɼ�
					j++;
				}
				printf("ͬѧ%d��\n", g[i]);										//�������
			}
			printf("��������Ҫɾ����ͬѧ�ɼ�");
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
					printf("ͬѧ%d��\n", g[i]);
				}
			}
			break;
		case 3:
			printf("�ɼ���ѯ��\n");
			printf("��������Ҫ���ҵ�ͬѧ�ɼ�");
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
					printf("ͬѧ%d��\n", g[i]);
				}
			}
			break;
		case 4:printf("�ɼ�����:\n");
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
		case 5:printf("���Сֵ:\n");
			for (i = 0, j = 0; i < 3; i++)
			{
				j = 0;
				while (n[i][j] != '\n')
				{
					printf("%c", n[i][j]);										//����ɼ�
					j++;
				}
				printf("ͬѧ%d��\n", g[i]);										//�������
			}
			max = min = g[0];
			for (i = 1; i < 3; i++)								//��������
			{
				if (g[i] > max)									//�����ֵ
					max = g[i];
				if (g[i] < min)								//����Сֵ
					min = g[i];
			}
			printf("max=%d min=%d", max, min);
			break;
		case 6:printf("ƽ����:\n");
			printf("ƽ����=%.4f", (g[1] + g[2] + g[0]) / 3.0);		//���ƽ����
			break;
		case 7:printf("չʾ�ɼ�:\n");
			for (i = 0, j = 0; i < 3; i++)
			{
				j = 0;
				while (n[i][j] != '\n')
				{
					printf("%c", n[i][j]);										//����ɼ�
					j++;
				}
				printf("ͬѧ%d��\n", g[i]);		//�������
			}break;
		case 8:printf("�˳�ϵͳ:\n");
			printf("�ټ�");
			goto end;

		}
		printf("����r�ص���ҳ");
		r = getchar();
		system("cls");
	}
end:	return 0;
}