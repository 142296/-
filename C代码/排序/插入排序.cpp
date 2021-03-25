#include<stdio.h>			//插入排序  从小到大
#include<stdlib.h>			//类似老师排身高
#include<time.h>
int main()
{
	srand(time(0));
	int a[10], t, j;
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 90 + 10;
	for (int i = 1; i < 10; i++)
	{
		t = a[i];                //待插入数
		for (j = i; j > 0; j--)
		{						
			if (t > a[j - 1])	//判断与前一个数的大小关系
			{					//大于前一个
				break;
			}
			else               //小于前一个
				a[j] = a[j - 1];		//继续前进
		}
		a[j] = t;				//（1）正常跳出循环  小于第一个
	}							//（2）break跳出循环 大于前一个
	for (j = 0; j < 10; j++)
		printf("%d ", a[j]);
}