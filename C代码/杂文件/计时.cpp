#include<stdio.h>          //计时
#include<time.h>
int main()
{
	int begin, end;
	begin = time(NULL);
	getchar();        //此处加需要计时的函数
	end = time(NULL);
	printf("%d", end);
}