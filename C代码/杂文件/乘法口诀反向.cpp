#include<stdio.h>
int main()
{
int i,j;
for(i=1;i<10;i++)
	{
		for(j=9;j>0;j--)
		{	if(i>=j)
			printf("%d*%d=%d\t",j,i,i*j);
		   else
			   printf("\t");
		}
		printf("\n");
	}
}