#include<stdio.h>
#include<stdlib.h>
int bk(char* dad, char* son)
{
	int i, j;
	for (i = 0; dad[i] != '\0'; i++)
	{
		for (j = 0; son[j] != '\0'; j++)
		{
			if (son[j] != dad[i + j])
				break;
		}
		if (son[j] == '\0')
			return 1;
	}
	return 0;
}
int main()
{
	char dad[20], son[10];
	gets_s(dad);
	gets_s(son);
	if (bk(dad, son))
		printf("ÊÇ");
	else printf("²»ÊÇ");
}