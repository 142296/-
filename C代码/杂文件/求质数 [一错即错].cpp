#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,c;
	for(m=2;m<100;m++)
	{
		c=1;
		for (n = 2; n <= sqrt(m); n++)
		{
			if (m % n == 0)
			{
				c = 0;
				break;
			}
		}
		if(c)
			printf("%d ",m);
	}

}
