#include<stdio.h>
#include<stdlib.h>
int bk(char* p, char* q);
int bk(char* dad, char* son)
{
	char* p = dad, * q = son;
	while (*p != *q)                                   //����ͬ��������
	{
		p++;
	}
	while (*p == *q && *q != '\0' && *q != '\0')      //������ͬ���ֱȽ�
	{
		p++; q++;
		if (*p != *q)
		{
			if (bk(p, son))             //ÿ��ݹ���һ��������ͬ��λ
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
		printf("��");
	else printf("����");
	return 0;
}