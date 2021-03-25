#include<stdio.h>
#include<stdlib.h>   //EOF==-1
int main()
{
	FILE* fp;
	char ch, ar[20];
	if ((fp = fopen("C:\\Users\\14229\\Desktop\\1.txt", "r")) == NULL)
	{
		printf("文件打开失败");
		exit(EXIT_FAILURE);     //文件打开失败宏
	}
	while ((ch = fgetc(fp)) != EOF)	 //从文件中获取一个字符，并使文件指针自增一
		printf("%c", ch);
	rewind(fp);                      //回到文件头
	while ((fgets(ar, 20, fp)))		//从文件中获取一个字符串，并自增n
	{
		printf("%s", ar);
	}
	fclose(fp);
}