#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int KMP(char* dad, char* son, int* next, int ldad, int lson)
{
	for (int i = 0, j = 0;; i++, j++)
	{
		if (j >= lson)		//�Ӵ�����
		{
			return 1;		//���سɹ�
		}
		else if (i >= ldad)		//�����������Ӵ�δ����
		{
			return 0;		//����ʧ��
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
			if (tt[j] == tt[l])						//������
			{
				key++;								//����+1
				j++; l++;							//ǰ��׺��ָ�������Ϊ
			}
			else									//��������
			{
				key = 0;							//������0
				j = 0;								//ǰ׺��ͷָ���0
				l1++;								//��׺��ͷָ�����
				l = l1;								//��׺��ָ�����ͷ
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
	getnext(tt, next, length);				//���next����
	if (KMP(Tt, tt, next, strlen(Tt), length))
	{
		printf("YES\n");
	}
	else
		printf("NO\n");
}