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
int calc(int (*fp)(int a, int b), int c, int d)  //�ص���
{
	return fp(c, d);
}
int (*s(char c))(int a, int b)     //���ݷ��ţ����غ���
{									//(*s(char c)) ���غ�����
	switch (c)						//(int a,int b)�Ǵ����غ����Ĳ�����
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
	printf("������:");
	scanf_s("%d%c", &a, &b);
	scanf_s("%d", &c);
	fp = s(b);
	printf("%d%c%d=%d", a, b, c, calc(fp, a, c));
}