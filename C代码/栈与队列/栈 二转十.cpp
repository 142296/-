#include<stdio.h>          //ջ ������תʮ����
#include<stdlib.h>
#include<math.h>

int main()
{
	int* top, * base, * array, i = 1, j = 0;
	int ten_num = 0;
	array = (int*)malloc(4 * 4);
	base = top = array;
	scanf_s("%1d", top);
	while (*top < 2)            //��ջ
	{
		top++;
		if (top - base >= i * 4 - 1)                    //ջ������
		{
			i++;
			array = (int*)realloc(array, i * 4 * 4);
		}
		scanf_s("%1d", top);
	}
	top--;
	while (top - base >= 0)           //��ջ
	{
		ten_num += *top * pow(2, j);
		j++;
		top--;
	}
	printf("%d", ten_num);
}