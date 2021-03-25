#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void zhuan(int a)
{
	int y;
	y = a % 2;
	if (a > 0)
		zhuan(a / 2);
	else
		return;
		printf("%d", y);
}

int main()
{
	int a;
	while (1) {
		printf("请输入整数数字\n");
		scanf_s("%d", &a);
		if (a >= 0)
		{
			printf("(%-7d)10=(0\t", a);
			zhuan(a);
		}
		else
		{
			int b;
			printf("转化为几位?\n");
			scanf_s("%d",& b);
			printf("(%-7d)10=(1\t",a);
			zhuan((-a ^ (int)(pow(2, b-1) - 1)) + 1);
		}
		printf(")2");
	}
	getchar();
	putchar('\n');
}