#include<stdio.h>
#include<stdlib.h>

struct list {
	char data;
	int key;
	list* lchild, * rchild;
};
void creat_tree(list** tree_head)			//ǰ�������ֵ
{
	char c;
	scanf_s("%c", &c);
	if (c == '#')
	{
		(*tree_head) = NULL;
	}
	else {
		(*tree_head) = (list*)malloc(sizeof(list));
		(*tree_head)->data = c;
		(*tree_head)->key = 0;
		creat_tree(&(*tree_head)->lchild);
		creat_tree(&(*tree_head)->rchild);
	}
}
void show(list* tree_head) {
	printf("%c ", tree_head->data);
}
void visit1_tree(list* tree_head)				//ǰ�����
{
	list* head[60];
	int top = -1, bot = -1;
	while (tree_head)
	{
		show(tree_head);
		if (tree_head->lchild)   //��������Ϊ��
		{
			top++;
			head[top] = tree_head->rchild;		//��������ջ
			tree_head = tree_head->lchild;
		}
		else  //������Ϊ��
		{
			if (tree_head->rchild)		//��������Ϊ��
			{
				tree_head = tree_head->rchild;
			}
			else						//����������Ϊ�� 
			{
				if (top == bot)
					break;
				tree_head = head[top];				//��ջ
				top--;
			}
		}
	}
}
void visit2_tree(list* tree_head)				//�������
{
	list* head[60], * temp;
	int top = -1, bot = -1;
	top++;
	head[top] = tree_head;
	while (1)
	{
		while ((temp = head[top]) && temp)			//ȡ��ջ��Ԫ�ز���֤��Ϊ��
		{
			top++;
			head[top] = temp->lchild;			//��������ջ
		}
		top--;									//����NULLԪ��
		if (top != bot)							//ջ�ǿ�
		{
			show(head[top]);					//���ջ��Ԫ��(�ض�û��������)
			head[top] = head[top]->rchild;		//ջ��Ԫ�ص�����������ջ��Ԫ��     
		}
		if (top == bot)
			break;
	}
}
void visit3_tree(list* tree_head)				//�������
{
	list* head[60], * temp = NULL;
	int top = -1, bot = -1;
	top++;
	head[top] = tree_head;
	while (1)
	{
		while ((temp = head[top]) && temp)
		{
			top++;
			head[top] = temp->lchild;
		}
		top--;
		if (top != bot)
		{
			while (top >= 0 && head[top]->key)
			{
				show(head[top]);
				head[top]->key = 0;		//key��ԭ����Ӱ���´α���
				top--;
			}
			if (top == bot)
				break;
			else
			{
				head[top]->key = 1;
				top++;
				head[top] = head[top - 1]->rchild;
			}
		}
	}
}
int main()
{
	list* tree_head;
	creat_tree(&tree_head);
	int n;
	list* move = tree_head;
	while (1)
	{
		printf("1.ǰ�� 2.���� 3.����");
		printf("������ѡ��:");
		scanf_s("%d", &n);
		switch (n) {
		case 1: visit1_tree(move); move = tree_head; break;
		case 2: visit2_tree(move); move = tree_head; break;
		case 3: visit3_tree(move); move = tree_head; break;
		default:break;
		}
		putchar('\n');

	}
}