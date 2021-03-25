#include<stdio.h>          //栈 二进制转十六进制
#include<stdlib.h>
#include<math.h>

int main()
	{
	int* top, * base, * array, i = 1, j = 0,sum,*sixteen_array,*top1,*base1,n=1;
	array = (int*)malloc(4 * 4);
	base = top = array;
	scanf_s("%1d", top);
	while (*top<2)            //进栈
	{
		top++;
		if (top - base >= i * 4-1)                    //栈溢出检查
		{
			i++;
			array = (int*)realloc(array, i * 4 * 4);
		}
		scanf_s("%1d", top);
	}
	top--;
	sixteen_array = (int*)malloc(4);
	top1 = base1 = sixteen_array;
	while (top-base>=0)           //出二栈 入十六栈
	{
		j = 4; sum = 0;
		while (j > 0&&top-base>=0)
		{
			sum += *top*pow(2, 4 - j);
			j--; top--;
		}
		while(top1-base1>=n)
			sixteen_array = (int*)realloc(sixteen_array, 4 * n);
		*top1 = sum;
		top1++;
		n++;
	}
	top1--;
	while (top1 - base1 >= 0)
	{
		printf("%c", *top1 < 10 ? *top1+'0' : *top1 - 10 + 'A');
		top1--;
	}
	return 0;
}