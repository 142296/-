#include<stdio.h>
#include<stdlib.h>
int bk(char* p, char* q);
int bk(char* dad, char* son)
{
	char* p = dad, * q = son;
	while (*p != *q)                                   //非相同部分舍弃
	{
		p++;
	}
	while (*p == *q && *q != '\0' && *q != '\0')      //部分相同部分比较
	{
		p++; q++;
		if (*p != *q)
		{
			if (bk(p, son))             //每层递归解决一个部分相同部位
				return 1;
		}
	}
	if (*q == '\0')
		return 1;
	else
		return 0;
}
int main()
{
	char str1[20], str2[10];
	gets_s(str1);
	gets_s(str2);
	if (bk(str1, str2))
		printf("是");
	else printf("不是");
	return 0;
}