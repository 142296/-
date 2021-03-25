#include<stdio.h>
char get(char c)
{
	switch (c)
	{
	case 'A':return 5;
	case 'b':return 6;
	}
}
int main()
{
	char (*q)(char c) = get;      //定义函数指针
	printf("%d\n", (*q)('A'));
}