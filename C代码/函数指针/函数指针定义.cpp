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
	char (*q)(char c) = get;      //���庯��ָ��
	printf("%d\n", (*q)('A'));
}