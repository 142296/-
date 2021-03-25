#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Huffman_tree {
	int key;
	char ch;
	Huffman_tree* next;
	Huffman_tree* lchild;
	Huffman_tree* rchild;
};
void Get_count(char a[], Huffman_tree** head, int length)		//�����ĸ���ִ���
{
	int count;
	for (int i = 0; i < length; i++)
	{
		count = 1;
		if (a[i] != 1)					//��Ϊ��ֵ��û��¼��
		{
			for (int j = i + 1; j < length; j++)
			{
				if (a[j] == a[i])
				{
					count++;				//����
					a[j] = 1;				//����ֵ����ʾ��¼��
				}
			}
			Huffman_tree* new_link;
			//�洢 ���ִ�������ĸ
			new_link = (Huffman_tree*)malloc(sizeof(Huffman_tree));
			new_link->ch = a[i];
			a[i] = 1;
			new_link->key = count;
			new_link->next = NULL;
			new_link->lchild = NULL;
			new_link->rchild = NULL;
			(*head)->next = new_link;
			*head = new_link;
		}
	}
}
void Huffman_Tree(Huffman_tree** head) {         //���ɹ�������
	while ((*head)->next->next)
	{
		Huffman_tree* min[2], * temp, * Node, * move, * temp1;
		for (int i = 0; i < 2; i++)
		{
			min[i] = (Huffman_tree*)malloc(sizeof(Huffman_tree));
			move = *head;
			min[i] = move;
			while (move->next)
			{
				if (move->next->key < min[i]->next->key)
				{
					min[i] = move;
				}
				move = move->next;
			}
			temp = min[i]->next;			//��min������ɾ��
			min[i]->next = temp->next;
			min[i] = temp;
			min[i]->next = NULL;		//ն�϶������֦
		}
		Node = (Huffman_tree*)malloc(sizeof(Huffman_tree));
		Node->lchild = min[0];
		Node->rchild = min[1];
		Node->key = min[0]->key + min[1]->key;
		temp1 = (*head)->next;
		(*head)->next = Node;
		Node->next = temp1;
	}
}
void show(Huffman_tree* head, int level, int a[])	//������������
{
	if (head)
	{
		if (head->ch > 0)
		{
			printf("%c������", head->ch);
			for (int i = 0; i < level; i++)
				printf("%d", a[i]);
			putchar('\n');
		}
		show(head->rchild, level + 1, a);
		a[level] = 1;
		show(head->lchild, level + 1, a);
		a[level] = 0;
	}
}
int main()
{
	char a[100];
	int length;
	gets_s(a);
	Huffman_tree* alp_head, * alp_move;
	alp_head = (Huffman_tree*)malloc(sizeof(Huffman_tree));
	alp_head->ch = 0;
	alp_head->key = 0;
	alp_head->next = NULL;
	alp_head->lchild = NULL;
	alp_head->rchild = NULL;
	alp_move = alp_head;
	length = strlen(a);
	Get_count(a, &alp_move, length);
	alp_move = alp_head;
	Huffman_Tree(&alp_move);
	int c[26] = { 0 };
	show(alp_head->next, 0, c);
}