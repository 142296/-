#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* base, * top;
	int* array, num, sloga;
	array = (int*)malloc(sizeof(int) * 32);
	base = top = array;
	scanf_s("%d", &num);
	if (!(sloga = (num >= 0)))                //符号判断
		num = -num;
	while (num)									//除二余一法
	{
		*top = num % 2;
		top++;
		num /= 2;
	}
	while (top - base < 31)						//补0
	{
		*top = 0;
		top++;
	}
	*top = sloga;								//符号位
	while (1)									//输出
	{
		printf("%d", *top);
		if (top == base)
			break;
		top--;
	}
}