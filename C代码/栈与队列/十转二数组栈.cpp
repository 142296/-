#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* base, * top;
	int* array, num, sloga;
	array = (int*)malloc(sizeof(int) * 32);
	base = top = array;
	scanf_s("%d", &num);
	if (!(sloga = (num >= 0)))                //�����ж�
		num = -num;
	while (num)									//������һ��
	{
		*top = num % 2;
		top++;
		num /= 2;
	}
	while (top - base < 31)						//��0
	{
		*top = 0;
		top++;
	}
	*top = sloga;								//����λ
	while (1)									//���
	{
		printf("%d", *top);
		if (top == base)
			break;
		top--;
	}
}