#include<stdio.h>
#include<string.h>
typedef struct node {
	char c[10];
	int grade;
	int age;
} date;
int main()
{
	date a;
	int i;
	for(i=0;i<10;i++)
	{
		/*a.c[i]=getchar();
		if(a.c[i]!='\n')*/
		if (a.c[i]=getchar() != '\n')
			continue;
		a.c[i] = 0;
		break;
	}
	for (i = 0; i < 10; i++)
	{
		if (a.c[i]!=0)
		{
			printf("%c", a.c[i]);
			continue;
		}
		break;
	}
}