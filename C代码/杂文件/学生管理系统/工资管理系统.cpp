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
		printf("�ļ�·������");
		return;
	}
	fprintf(fp,"���\t����\tнˮ\n");
	while (head != NULL)
	{
		fprintf(fp,"%d\t%s\t%d\n", head->ID, head->name, head->salary);
		head = head->next;
	}
	fclose(fp);
	printf("����ɹ�");
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
				(move)->salary ^= head1->salary;			//��򽻻���
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
	printf("������Ҫɾ�����");
	scanf("%d", &del);
	getchar();
	if ((*head)->ID == del)              //ɾ��ͷָ��
	{
		printf("ɾ��%d��%s ��н%d(Y/N)", (*head)->ID, (*head)->name, (*head)->salary);
		ch = getchar();
		if (ch == 'Y' || ch == 'y')
			(*head) = (*head)->next;
	}
	else {											//��ͷָ��
		while ((*head)->next != NULL && (*head)->next->ID != del)
		{
			*head = (*head)->next;
		}
		if ((*head)->next == NULL)
		{
			printf("û�е�ǰ���");
			return;
		}
		printf("ɾ��%d��%s ��н%d(Y/N)", (*head)->next->ID, (*head)->next->name, (*head)->next->salary);
		ch = getchar();
		if (ch == 'Y' || ch == 'y')
			(*head)->next = (*head)->next->next;
	}
}
void find(employee* head)
{
	int target;
	printf("������Ҫ��ѯ�ı��");
	scanf("%d", &target);
	getchar();
	while (head != NULL && head->ID != target)
		head = head->next;
	printf("���\t����\tнˮ\n");
	printf("%d\t%s\t%d", head->ID, head->name, head->salary);

}
void output(employee* head)
{
	printf("���\t����\tнˮ\n");
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
		printf("����:");
		gets_s(emp->name);
		printf("���");
		scanf("%d", &emp->ID);
		getchar();
		printf("нˮ");
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
	printf("��ӭ���빤�ʹ���ϵͳ������������:");
	scanf("%d", &password);
	getchar();
	if (password == pass)
	{
		begin = time(0);
		printf("������ȷ");
		while (time(0) <= begin);
		system("cls");
	}
	else
	{
		printf("�������");
		goto A;
	}
	while (1)
	{
		system("cls");
		printf("********Ա�����ʹ���ϵͳ**********\n");
		printf("1.¼��Ա�����乤����Ϣ\n");
		printf("2.��ʾԱ����Ϣ\n");
		printf("3.��ѯ������Ϣ\n");
		printf("4.ɾ��ĳԱ����Ϣ\n");
		printf("5.��������\n");
		printf("6.�����ļ�\n");
		printf("��ѡ��1\\2\\3\\4\\5\\6����");
		scanf("%d", &choice);
		getchar();
		system("cls");
		switch (choice)
		{
		case 1:
			printf("������Ա������");
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
			printf("��Ч����");
		}
	}
}