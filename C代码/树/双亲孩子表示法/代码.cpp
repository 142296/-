#include<stdio.h>
#include<stdlib.h>
struct list {
	int array[20];
	int length;
};
void show(list* a)
{
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", a->array[i]);
	}
}
void function1(list** array, int x, int y)
{
	int i, j;
	(*array)->array = (int*)realloc(*array, sizeof(int) * (*array)->length + 1);
	for (i = 0; i <= (*array)->length; i++)
		if ((*array)->array[i] == y)
			break;
	(*array)->length += 1;
	for (j = (*array)->length - 1; j >= i; j--)
	{
		(*array)->array[j] = (*array)->array[j - 1];
	}
	(*array)->array[i] = x;
}
void function2(list** a)
{
	int i, j, n = 0;
	for (i = 0; i < (*a)->length; i++)
	{
		if ((*a)->array[i] % 2)
			n++;		//奇数个数
	}
	for (i = 0; i < n; i++)
	{
		if ((*a)->array[i] % 2 == 0) //偶数
			for (j = n; j < (*a)->length; j++)
			{
				if ((*a)->array[j] % 2)  //奇数
				{
					(*a)->array[j] ^= (*a)->array[i];
					(*a)->array[i] ^= (*a)->array[j];
					(*a)->array[j] ^= (*a)->array[i];
				}
			}
	}
}
int main()
{
	list* array;
	array = (list*)malloc(sizeof(list));
	for (int i = 0; i < 20; i++)
	{
		array->array[i] = i;
	}
	array->length = 20;
	show(array);
	printf("\n");
	function1(&array, 10, 5);  //将10插在5前面
	show(array);
}