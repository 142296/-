#include<stdio.h>
long count;
int hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("%c-->%c\n", x, z);
		count++;
	}
	else
	{
		hanoi(n - 1, x, z, y);            //将n-1个盘子从x借助z移到y上
		printf("%c-->%c\n", x, z);		//将第n个盘子从x移到z上
		count++;
		hanoi(n - 1, y, x, z);          //将n-1个盘子从y借助x移动到z上
	}
	return count;
}
int main()
{
	while (1)
	{
		printf("请输入层数");
		int a;
		count = 0;
		scanf_s("%ld", &a);
		printf("\n%d步\n", hanoi(a, 'X', 'Y', 'Z'));

	}
}