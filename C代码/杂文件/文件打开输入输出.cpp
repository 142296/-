#include<stdio.h>
int main()
{
	FILE* fp;
	char ch;
	char a[20]="hello world";
	fp=(FILE*)fopen("1.txt","w");
	if(!feof(fp))              //feof(*)�򿪷���1δ�򿪷���0
		{
			fprintf(fp,"%s",a);						//д��a         
			fputc('!',fp);							//д��!
			fclose(fp);
		}
	else 
		printf("��ʧ��");
	fp=(FILE*)fopen("1.txt","r");
	if(!feof(fp)) 
	{
		fscanf(fp,"%s",a);							//���ļ���ֵ��a
		fclose(fp);
	}
	else printf("��ʧ��!");
	fp=(FILE*)fopen("1.txt","r");
	if(!feof(fp)) 
	{
		ch=fgetc(fp);
		while(!feof(fp))				//���ļ�û�н���
		{
			printf("%c",ch);
			ch=fgetc(fp);             //ch������һ���ַ�
		}
	}
}