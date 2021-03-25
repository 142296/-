#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int a[]);  //ð��
void select(int a[]);	//ѡ��	
void insert(int a[]);	//����
void renovate(int a[]);	//��������
void show(int a[]);		//չʾ����
void swap(int*, int*);    //����

void swap(int* a, int* b)  //����
{
	int t = *a; *a = *b; *b = t;
}
void bubble(int a[])    //ð��
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 8; j >= i; j--)
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
	}
}
void select(int a[])   //ѡ��
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (a[i] > a[j])
				swap(&a[i], &a[j]);
		}
	}
}
void insert(int a[])   //����
{
	for (int i = 1, j; i < 10; i++)
	{
		int t = a[i];
		for (j = i; j > 0; j--)
		{
			if (a[j - 1] < t)
				break;
			else
				a[j] = a[j - 1];
		}
		a[j] = t;
	}
}
void renovate(int a[])     //�����鸳�����
{
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 90 + 10;
}
void show(int a[])       //�������
{
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int main()
{
	srand(time(0));
	int a[10];
	renovate(a);    //ˢ�º���
	bubble(a);		//����
	show(a);		//չʾ
	renovate(a);	//ˢ��	
	select(a);		//����
	show(a);		//չʾ
	renovate(a);	//ˢ��
	insert(a);		//����
	show(a);		//չʾ
}