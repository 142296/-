#include<stdio.h>          //��ʱ
#include<time.h>
int main()
{
	int begin, end;
	begin = time(NULL);
	getchar();        //�˴�����Ҫ��ʱ�ĺ���
	end = time(NULL);
	printf("%d", end);
}