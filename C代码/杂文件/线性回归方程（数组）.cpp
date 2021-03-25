#include<stdio.h>
#include<math.h>
int main()
{
	int club,i,count;
	club = 0;
	float  sum1 = 0.0, sum2 = 0.0, b1 = 0.0, b2 = 0.0;
	float a=0, b=0;
	printf("How many clubs?");
	scanf_s("%d", &count);
	float xy[1000][2];
	for (i = 0; i < count; i++)
	{
			scanf_s("%f %f", &xy[i][0],&xy[i][1]);
			sum1 = sum1 + xy[i][0];
			sum2 = sum2 + xy[i][1];
			
	}for (i = 0; i < count; i++)
	{
		b1 += (xy[i][0] - 1.0*sum1 / count) * (xy[i][1] - 1.0*sum2 / count);
		b2 += (xy[i][0] - 1.0*sum1 / count) * (xy[i][0] - 1.0*sum1 / count);
		b = 1.0*b1 / b2;
		a = (1.0*sum2 / count )-(1.0* b * sum1 / count);
	}
	printf("a=%f b=%f", a, b);
}