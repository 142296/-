#include<stdio.h>
#include<stdlib.h>   //EOF==-1
int main()
{
	FILE* fp;
	char ch, ar[20];
	if ((fp = fopen("C:\\Users\\14229\\Desktop\\1.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��");
		exit(EXIT_FAILURE);     //�ļ���ʧ�ܺ�
	}
	while ((ch = fgetc(fp)) != EOF)	 //���ļ��л�ȡһ���ַ�����ʹ�ļ�ָ������һ
		printf("%c", ch);
	rewind(fp);                      //�ص��ļ�ͷ
	while ((fgets(ar, 20, fp)))		//���ļ��л�ȡһ���ַ�����������n
	{
		printf("%s", ar);
	}
	fclose(fp);
}