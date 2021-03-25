#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int KMP(char* dad, char* son, int* next, int ldad, int lson)
{
	for (int i = 0, j = 0;; i++, j++)
	{
		if (j >= lson)		//子串结束
		{
			return 1;		//返回成功
		}
		else if (i >= ldad)		//父串结束，子串未结束
		{
			return 0;		//返回失败
		}
		if (dad[i] != son[j])
		{
			if (j == 0)
			{
				j--;
				continue;
			}
			i--;
			j = next[j] - 1;
		}
	}
}
void getnext(char tt[], int next[], int lenth)
{
	next[0] = -1;
	next[1] = 0;
	for (int i = 1; i < lenth - 1; i++)
	{
		int key = 0;
		for (int j = 0, l = 1, l1 = 1; j < i && l <= i;)
		{
			if (tt[j] == tt[l])						//相等情况
			{
				key++;								//计数+1
				j++; l++;							//前后缀表指针后移以为
			}
			else									//不相等情况
			{
				key = 0;							//计数归0
				j = 0;								//前缀表头指针归0
				l1++;								//后缀表头指针后移
				l = l1;								//后缀表指针回至头
			}
		}
		next[i + 1] = key;
	}
}
int main()
{
	int next[10], length;
	char tt[20], Tt[50];
	gets_s(Tt);
	gets_s(tt);
	length = strlen(tt);
	getnext(tt, next, length);				//获得next数组
	if (KMP(Tt, tt, next, strlen(Tt), length))
	{
		printf("YES\n");
	}
	else
		printf("NO\n");
}