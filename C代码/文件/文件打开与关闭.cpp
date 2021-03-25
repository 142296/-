#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fp;
	char ch;
	if ((fp = fopen("C:\\Users\\14229\\Desktop\\1.txt", "w")) == NULL)
	{
		printf("文件打开失败");
		exit(EXIT_FAILURE);     //文件打开失败宏
	}
	fclose(fp);
}