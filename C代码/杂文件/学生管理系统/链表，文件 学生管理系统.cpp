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
	printf("请输入名字:");
	gets_s(member->name);
	printf("请输入成绩:");
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
		printf("%d:%s同学%.2f分\n", i++, move->name, move->grade);
		move = move->next;
	}
}
void del(St** student)
{
	int del;
	St* move = *student;
	output(*student);
	printf("请输入要删除学生的序号");
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
	printf("请输入想找的人名");
	gets_s(findname);
	while (move != NULL)
	{
		if (!(strcmp(findname, move->name)))
		{
			printf("%s同学%.2f分\n", move->name, move->grade);
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
		fprintf(fp, "序号\t姓名\t成绩\n");
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
		printf("学生成绩管理系统\n\n");
		printf("****************************************\n");
		printf("*               主菜单                 *\n");
		printf("****************************************\n\n");
		printf("  1:成绩输入\t\t2：成绩删除\n");
		printf("  3:成绩查询\t\t4：成绩排序\n");
		printf("  5:显示成绩\t\t6：保存为文件\n");
		printf("请输入数字");
	begin:	scanf_s("%d", &a);
		system("cls");
		getchar();
		switch (a)
		{
		case 1:
			printf("请输入本次输入人数:");
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
			printf("完成");
			  else printf("打开文件失败");
			break;
		default:printf("请输入正确的数字");
			goto begin;
		}
		printf("输入'r'返回主界面");
		scanf_s("%c", &r);
		system("cls");
	}
}