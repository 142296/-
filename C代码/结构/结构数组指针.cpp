#include<stdio.h>         //结构+指针&&结构+数组
int main()
{
	struct a {
		char initial;
		int days;
	};
	a month[12];
	a(*p) = month;
	for (int i = 0; i < 12; i++)
	{
		if (i % 2)
		{
			p[i].days = 31;
			p[i].initial = 'A';
		}
		else {
			p[i].days = 30;
			p[i].initial = 'B';
		}
	}
	for (int i = 0; i < 12; i++)
	{
		printf("%d月首字母是%c有%d天\n", i + 1, month[i].initial, month[i].days);
	}
}