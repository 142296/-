#include<stdio.h>
#include<math.h>
void huan(int a,int b)
  {
	int c;
	c = a % b;   //除b余数法
	if (a > 0)
		huan(a / b, b);
	else
		return;
	if (c < 10)
		printf("%d", c);
	else
		printf("%c", 'a' + c - 10);
}
int main()
{
	while (1)
	{
		int a, b, c;
		printf("输入 数和转换进制数");
		scanf_s("%d%d", &a, &b);
		printf("(%d)10=(", a);    //记录原始数据
		huan(a, b);
		printf(")%d", b);
	}
}
