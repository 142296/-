#include<stdio.h>
int add(int, int);
int sub(int, int);
int calc(int (*fp)(int, int), int, int);
int (*s(char c))(int a, int b);
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int calc(int (*fp)(int a, int b), int c, int d)  //重点行
{
	return fp(c, d);
}
int (*s(char c))(int a, int b)     //根据符号，返回函数
{									//(*s(char c)) 返回函数名
	switch (c)						//(int a,int b)是待返回函数的参数；
	{
	case '+':return add;
	case '-':return sub;
	}
}
int main()
{
	int a, c;
	char b;
	int (*fp)(int, int);
	printf("请输入:");
	scanf_s("%d%c", &a, &b);
	scanf_s("%d", &c);
	fp = s(b);
	printf("%d%c%d=%d", a, b, c, calc(fp, a, c));
}