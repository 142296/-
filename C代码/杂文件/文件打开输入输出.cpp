#include<stdio.h>
int main()
{
	FILE* fp;
	char ch;
	char a[20]="hello world";
	fp=(FILE*)fopen("1.txt","w");
	if(!feof(fp))              //feof(*)打开返回1未打开返回0
		{
			fprintf(fp,"%s",a);						//写入a         
			fputc('!',fp);							//写入!
			fclose(fp);
		}
	else 
		printf("打开失败");
	fp=(FILE*)fopen("1.txt","r");
	if(!feof(fp)) 
	{
		fscanf(fp,"%s",a);							//把文件赋值给a
		fclose(fp);
	}
	else printf("打开失败!");
	fp=(FILE*)fopen("1.txt","r");
	if(!feof(fp)) 
	{
		ch=fgetc(fp);
		while(!feof(fp))				//在文件没有结束
		{
			printf("%c",ch);
			ch=fgetc(fp);             //ch保存下一个字符
		}
	}
}