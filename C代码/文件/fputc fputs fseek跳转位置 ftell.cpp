#include<stdio.h>
#include<stdlib.h>   //EOF==-1
int main()
{
	FILE* fp;
	char ch, ar[20];
	if ((fp = fopen("C:\\Users\\14229\\Desktop\\1.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��");
		exit(EXIT_FAILURE);     //�ļ���ʧ�ܺ�
	}
	while ((ch = getchar()) != '0')
		fputc(ch, fp);
	ftell(fp);
	fseek(fp, 0, 0);   //(�ļ�����ƫ������ƫ����ʼλ��) 0���ļ�ͷ 1���ļ���ǰλ�� 2���ļ�β
	fclose(fp);
}