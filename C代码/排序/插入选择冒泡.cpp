#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int a[]);  //冒泡
void select(int a[]);	//选择	
void insert(int a[]);	//插入
void renovate(int a[]);	//重置数组
void show(int a[]);		//展示数组
void swap(int*, int*);    //交换

void swap(int* a, int* b)  //交换
{
	int t = *a; *a = *b; *b = t;
}
void bubble(int a[])    //冒泡
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 8; j >= i; j--)
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
	}
}
void select(int a[])   //选择
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
void insert(int a[])   //插入
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
void renovate(int a[])     //给数组赋随机数
{
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 90 + 10;
}
void show(int a[])       //输出数组
{
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int main()
{
	srand(time(0));
	int a[10];
	renovate(a);    //刷新函数
	bubble(a);		//排序
	show(a);		//展示
	renovate(a);	//刷新	
	select(a);		//排序
	show(a);		//展示
	renovate(a);	//刷新
	insert(a);		//排序
	show(a);		//展示
}