#include<stdio.h>          /*只会写整数和正小数的二进制转换*/
#include<math.h>
int main()
{
	int a, b, c, d, e,q;
	 float f, g;
	
	
	while(1)
	{
		scanf_s("%f", &f);
		c = 0;
		d = 0;
		a = f;				/*提取原始整数*/
		e = a;				/*记录原始整数*/
		g = f;				/*记录原始数据*/
		while (a != 0)
		{
			b = a % 2;
			d = d + b * pow(10, c);    /*输出的整数量*/
			c = c + 1;
			a = (a - b) / 2;
		}
		f = f - e;					/*提取原始小数*/
		int  i;
		float  h;
		double j;
		j = 0;
		i = 0;
		h = f;					/*记录原始小数*/
		while (f != 0 && i > -8)  /*保留八位小数*/
		{
			i = i - 1;
			f = f * 2;
			if (f >= 1)
			{
				j = j + 1 * pow(10, i);	/*输出的小数量*/

				f = f - 1;
			}
		}

		printf("(%d)10=(%d)2\n", e, d);  /*整数转换*/
		printf("(%f)10=(%lf)2\n", h, j);   /*小数转换*/
		printf("(%f)10=(%f)2(q to quit)\n", g, d + j);  /*整体转换*/
		
		
			
	}
	
	return 0;
}