/*约瑟夫环问题即设有n个人坐成一个圈，从某个人开始报数，数到m
的人出列，接着从出列的下一个人开始重新报数，数到m的人再次出列，如此循环，直到所有人都出列为止，最后按照出列顺序输出*/
#include<stdio.h>
#include<stdlib.h>
struct yuesefu {
	int ID;
	struct yuesefu* next;
};
int main()
{
	int n, i, j, m;
	struct yuesefu* head, * p, * del;
	scanf_s("%d%d", &n, &m);
	head = (struct yuesefu*)malloc(sizeof(yuesefu));
	p = head;
	head->next = NULL;
	head->ID = 1;
	for (i = 2; i <= n; i++)
	{
		p->next = (struct yuesefu*)malloc(sizeof(yuesefu));
		p = p->next;
		p->ID = i;
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