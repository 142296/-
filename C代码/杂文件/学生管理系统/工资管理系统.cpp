#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct employee {
	int ID;
	int salary;
	char name[20];
	employee* next;
};
void input(employee** head, int count);
void output(employee* head);
void find(employee* head);
void del(employee** head);
void sort(employee**);
void save(employee*);

void save(employee*head)
{
	FILE*fp=fopen("1.txt","w");
	if(fp==NULL)
	{	
		printf("文件路径错误");
		return;
	}
	fprintf(fp,"编号\t姓名\t薪水\n");
	while (head != NULL)
	{
		fprintf(fp,"%d\t%s\t%d\n", head->ID, head->name, head->salary);
		head = head->next;
	}
	fclose(fp);
	printf("保存成功");
}
void sort(employee** head)
{
	int ID, salary;
	char name[20];
	employee* move = *head;
	while (move != NULL)
	{
		employee* head1=(move)->next;
		while (head1 != NULL)
		{
			if ((move)->salary < head1->salary)
			{
				(move)->salary ^= head1->salary;			//异或交换法
				head1->salary ^= (move)->salary;
				(move)->salary ^= head1->salary;
				(move)->ID ^= head1->ID;
				head1->ID ^= (move)->ID;
				(move)->ID ^= head1->ID;
				strcpy(name, (move)->name);
				strcpy((move)->name, head1->name);
				strcpy(head1->name,name);
			}
			head1 = head1->next;
		}
		(move) = (move)->next;
	}
}
void del(employee** head)
{
	int del;
	char ch;
	printf("请输入要删除编号");
	scanf("%d", &del);
	getchar();
	if ((*head)->ID == del)              //删除头指针
	{
		printf("删除%d号%s 月薪%d(Y/N)", (*head)->ID, (*head)->name, (*head)->salary);
		ch = getchar();
		if (ch == 'Y' || ch == 'y')
			(*head) = (*head)->next;
	}
	else {											//非头指针
		while ((*head)->next != NULL && (*head)->next->ID != del)
		{
			*head = (*head)->next;
		}
		if ((*head)->next == NULL)
		{
			printf("没有当前编号");
			return;
		}
		printf("删除%d号%s 月薪%d(Y/N)", (*head)->next->ID, (*head)->next->name, (*head)->next->salary);
		ch = getchar();
		if (ch == 'Y' || ch == 'y')
			(*head)->next = (*head)->next->next;
	}
}
void find(employee* head)
{
	int target;
	printf("请输入要查询的编号");
	scanf("%d", &target);
	getchar();
	while (head != NULL && head->ID != target)
		head = head->next;
	printf("编号\t姓名\t薪水\n");
	printf("%d\t%s\t%d", head->ID, head->name, head->salary);

}
void output(employee* head)
{
	printf("编号\t姓名\t薪水\n");
	while (head != NULL)
	{
		printf("%d\t%s\t%d\n", head->ID, head->name, head->salary);
		head = head->next;
	}
}

void input(employee** head, int count)
{
	while (count--)
	{
		employee* emp, * temp;
		emp = (employee*)malloc(sizeof(employee));
		printf("姓名:");
		gets_s(emp->name);
		printf("编号");
		scanf("%d", &emp->ID);
		getchar();
		printf("薪水");
		scanf("%d", &emp->salary);
		getchar();
		temp = *head;
		*head = emp;
		emp->next = temp;
	}
}
int main()
{
A:	int password, pass = 12345678;
	int begin, choice, n;
	employee* head = NULL;
	printf("欢迎进入工资管理系统，请输入密码:");
	scanf("%d", &password);
	getchar();
	if (password == pass)
	{
		begin = time(0);
		printf("密码正确");
		while (time(0) <= begin);
		system("cls");
	}
	else
	{
		printf("密码错误");
		goto A;
	}
	while (1)
	{
		system("cls");
		printf("********员工工资管理系统**********\n");
		printf("1.录入员工及其工资信息\n");
		printf("2.显示员工信息\n");
		printf("3.查询工资信息\n");
		printf("4.删除某员工信息\n");
		printf("5.工资排序\n");
		printf("6.保存文件\n");
		printf("请选择【1\\2\\3\\4\\5\\6】：");
		scanf("%d", &choice);
		getchar();
		system("cls");
		switch (choice)
		{
		case 1:
			printf("请输入员工人数");
			scanf("%d", &n);
			getchar();
			input(&head, n);
			break;
		case 2:
			output(head);
			getchar();
			break;
		case 3:
			find(head);
			getchar();
			break;
		case 4:
			del(&head);
			break;
		case 5:
			sort(&head);
			output(head);
			getchar();
			break;
		case 6:
			save(head);
			getchar();
			break;
		default:
			printf("无效数字");
		}
	}
}