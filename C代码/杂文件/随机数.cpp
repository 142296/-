#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));    //以时间为种子
	printf("%d", rand());
}