/*Լɪ�����⼴����n��������һ��Ȧ����ĳ���˿�ʼ����������m
���˳��У����Ŵӳ��е���һ���˿�ʼ���±���������m�����ٴγ��У����ѭ����ֱ�������˶�����Ϊֹ������ճ���˳�����*/
#include<stdio.h>
#include<stdlib.h>
struct yuesefu {
	int ID;
	struct yuesefu* next;
};
int main()
{
	int n, i, j, m;
	struct yuesefu* head = NULL, * p, * q, * del;
	scanf_s("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		q = (struct yuesefu*)malloc(sizeof(yuesefu));
		q->ID = i;
		if (head == NULL)
		{
			head = q;
			p = head;
		}
		else
		{
			p->next = q;
			p = q;
		}

	}
	p->next = head;
	for (p = head, j = 2;; p = p->next, j++)
	{
		if (p->next == p)
		{
			printf("%d", p->ID);
			break;
		}
		if (j % m == 0)
		{
			printf("%d->", p->next->ID);
			del = p->next;
			j++;
			p->next = del->next;
			free(del);
		}
	}
}