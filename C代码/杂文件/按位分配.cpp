#include<stdio.h>
int main()
{
	struct Test {              //��֮����������Ͱ�λ����
		unsigned char a : 4;
		unsigned char b : 1;
		unsigned char c : 3;
	};
	struct Test test;
	test.a = 9;
	test.b = 1;
	test.c = 7;
	printf("a=%d,b=%d,c=%d\n", test.a, test.b, test.c);
	printf("size:%d", sizeof(test));
}
