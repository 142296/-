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
void output(St sheet[], int n);      //����ɼ�
int input(St sheet[], int n);		//���뱣��ɼ�
void sort(St sheet[], int n);		//����
void swap(float* p, float* q);      //�����ɼ�

void swap(float* p, float* q)
{
	float t = *p; *p = *q; *q = t;
}
int input(St sheet[])
{
	int n;
	printf("�ɼ����룺\n����������(n<%d)\n", N);
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		printf("������ѧ��");
		scanf_s("%d", &sheet[i].ID);
		getchar();
		printf("��������ѧ�ɼ�");
		scanf_s("%f", &sheet[i].MScore);											//���ܳɼ�
		getchar();
		printf("������Ӣ��ɼ�");
		scanf_s("%f", &sheet[i].EScore);											//���ܳɼ�
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
	printf("ѧ��\t��ѧ\tӢ��\n");
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
		printf("ѧ���ɼ�����ϵͳ\n\n");
		printf("****************************************\n");
		printf("*               ���˵�                 *\n");
		printf("****************************************\n\n");
		printf("  1:�ɼ�����\t\t2����ʾ�ɼ�\n");
		printf("  3:�ɼ�����\t\t4���˳�ϵͳ\n");
		printf("����������");
		scanf_s("%d", &a);
		system("cls");
		getchar();
		switch (a)
		{
		case 1:n = input(sheet); break;
		case 2:output(sheet, n); break;
		case 3:printf("1.Ӣ��ɼ�����\n2.��ѧ�ɼ�����\n3.�ܳɼ�����\n4.ѧ������\n����������");
			scanf_s("%d", &b);
			getchar();
			switch (b)
			{
			case 1:sort(sheet, n, 'E'); break;
			case 2:sort(sheet, n, 'M'); break;
			case 3:sort(sheet, n, 'A'); break;
			case 4:sort(sheet, n, 'I'); break;
			}break;
		case 4:printf("�˳�ϵͳ:\n");
			printf("�ټ�");
			goto end;
		default:printf("��������Ч�ַ�");
		}
		printf("\n����r������ҳ");
		r = getchar();
		system("cls");
	}
end:return 0;
}