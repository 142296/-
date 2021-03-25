#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student {
	char name[20];
	float grade;
	Student* next;
}St;
typedef struct Student1 {
	char name[20];
	float grade;
}St1;
void input(St** student)
{
	int n;
	St* member, * temp;
	member = (St*)malloc(sizeof(St));
	printf("����������:");
	gets_s(member->name);
	printf("������ɼ�:");
	scanf_s("%f", &member->grade);
	getchar();
	temp = *student;
	*student = member;
	member->next = temp;
}
void output(St* student)
{
	int i = 1;
	St* move = student;
	while (move != NULL)
	{
		printf("%d:%sͬѧ%.2f��\n", i++, move->name, move->grade);
		move = move->next;
	}
}
void del(St** student)
{
	int del;
	St* move = *student;
	output(*student);
	printf("������Ҫɾ��ѧ�������");
	scanf_s("%d", &del);
	getchar();
	while (--del - 1)
	{
		move = move->next;
	}
	move->next = move->next->next;
}
void find(St* student)
{
	St* move = student;
	char findname[20];
	printf("���������ҵ�����");
	gets_s(findname);
	while (move != NULL)
	{
		if (!(strcmp(findname, move->name)))
		{
			printf("%sͬѧ%.2f��\n", move->name, move->grade);
			break;
		}
		move = move->next;
	}
}
void sort(St** student)
{
	St* move1 = *student, * move2 = *student;
	St1* temp = NULL;
	temp = (St1*)malloc(sizeof(St1));
	for (; move1->next != NULL; move1 = move1->next)
	{
		for (move2 = move1->next; move2 != NULL; move2 = move2->next)
		{
			if (move1->grade < move2->grade)
			{
				temp->grade = move1->grade;
				move1->grade = move2->grade;
				move2->grade = temp->grade;
				strcpy_s(temp->name, move1->name);
				strcpy_s(move1->name, move2->name);
				strcpy_s(move2->name, temp->name);
			}
		}
	}
	output(*student);
}
int save(St* student)
{
	FILE* fp;
	int num = 1;
	St* move = student;
	if (fp = fopen("C:\\Users\\14229\\Desktop\\student.txt", "w"))
	{
		fprintf(fp, "���\t����\t�ɼ�\n");
		while (move != 0)
		{
			fprintf(fp, "%d\t%s\t%.2f\n", num++, move->name, move->grade);
			move = move->next;
		}
		fclose(fp);
		return 1;
	}
	else
		return 0;
}
int main()
{
	char r;
	int a, n = 0;
	St* student = NULL;
	for (r = 'r'; r == 'r';)
	{
		printf("ѧ���ɼ�����ϵͳ\n\n");
		printf("****************************************\n");
		printf("*               ���˵�                 *\n");
		printf("****************************************\n\n");
		printf("  1:�ɼ�����\t\t2���ɼ�ɾ��\n");
		printf("  3:�ɼ���ѯ\t\t4���ɼ�����\n");
		printf("  5:��ʾ�ɼ�\t\t6������Ϊ�ļ�\n");
		printf("����������");
	begin:	scanf_s("%d", &a);
		system("cls");
		getchar();
		switch (a)
		{
		case 1:
			printf("�����뱾����������:");
			scanf_s("%d", &n);
			getchar();
			while (n--)
				input(&student);
			break;
		case 2:del(&student); break;
		case 3:find(student); break;
		case 4:sort(&student); break;
		case 5:output(student); break;
		case 6:if (save(student))
			printf("���");
			  else printf("���ļ�ʧ��");
			break;
		default:printf("��������ȷ������");
			goto begin;
		}
		printf("����'r'����������");
		scanf_s("%c", &r);
		system("cls");
	}
}