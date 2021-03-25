#include<stdio.h>
void zheng(int a)
{
	if (a != 0)
		zheng(a >> 1);
	if (a & 1)
		printf("1");
	else
		printf("0");
}
//void xiao(float b, int c)
//{
//	if (c > 0)
//	{
//		b *= 2;
//		if (b >= 1)
//		{
//			printf("1");
//			b -= 1;
//		}
//		else
//			printf("0");
//		xiao(b, c - 1)
//	}
//}
int main()
{
	while (1)
	{
		int a, b;
		float f, e;
		scanf_s("%f", &f);
		e = f;			/*记录原始数据*/
		a = f;         /*提取整数部分*/
		printf("输入你想保留的小数位数");
		scanf_s("%d", &b);
		printf("(%f)10=(", e);
		zheng(a);    /*整数部分算法*/
		f -= a;		/*提取小数部分*/
		printf(".");
		zheng(f<<b);
		printf(")2\n");
	}
}
