#include<stdio.h>
#include<stdlib.h>   //EOF==-1
int main()
{
	FILE* fp;
	char ch, ar[20];
	if ((fp = fopen("C:\\Users\\14229\\Desktop\\1.txt", "w")) == NULL)
	{
		printf("文件打开失败");
		exit(EXIT_FAILURE);     //文件打开失败宏
	}
	while ((ch = getchar()) != '0')
		fputc(ch, fp);
	ftell(fp);
	fseek(fp, 0, 0);   //(文件名，偏移量，偏移起始位置) 0是文件头 1是文件当前位置 2是文件尾
	fclose(fp);
}