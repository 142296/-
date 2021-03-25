#include<stdio.h>
#include<time.h>
#include<stdlib.h>                                //顾客 小于10  随机出现    咨询时间随机(1,2,3),
typedef struct customer {
	int min;
	customer* next;
} C;
void zixun(C** head, int*);
int pai(C** head);
int css = 1;
int pai(C** head)
{
	int num = 1;
	C* tail = *head, * newcustomer;
	if (tail == NULL)
	{
		*head = (C*)malloc(sizeof(C));
		(*head)->min = rand() % 3 + 1;
		(*head)->next = NULL;
		return 0;
	}
	while (tail->next != NULL)                 //寻找尾指针
	{
		num++;
		tail = tail->next;
	}
	if (num < 10)
	{
		if (rand() % 2)
		{
			css++;
			newcustomer = (C*)malloc(sizeof(C));
			newcustomer->min = rand() % 3 + 1;
			newcustomer->next = NULL;
			tail->next = newcustomer;
			printf("有%d个顾客", num + 1);
		}
		else
		{
			printf("有%d个顾客", num);
			return 1;
		}
	}
	else
		printf("有%d个顾客", num);
	return 1;
}
void zixun(C** head, int* T)
{
	C* temp;
	if (*T >= (*head)->min)
	{
		*T = 0;
		temp = *head;
		*head = (*head)->next;
		free(temp);
		printf("\t一位顾客咨询完成");
	}
}
int main()
{
	customer* head;
	int T = 0, sum = 0, freetime = 0;
	srand(time(0));
	head = (C*)malloc(sizeof(C));
	head->min = rand() % 3 + 1;
	head->next = NULL;
	while (sum < 100000)
	{
		if (!pai(&head))
		{
			printf("当前无顾客\n");
			freetime++;
			T = 0;
			sum++;
			continue;
		}
		if (head->min - T)
			printf("\t当前顾客需要%d分钟", head->min - T);
		zixun(&head, &T);
		T++;
		sum++;
		printf("\t当前时间%d分,共%d个顾客", sum, css);
		putchar('\n');
	}
	printf("空闲时间%d分钟", freetime);
}