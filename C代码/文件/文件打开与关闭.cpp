#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fp;
	char ch;
	if ((fp = fopen("C:\\Users\\14229\\Desktop\\1.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ��");
		exit(EXIT_FAILURE);     //�ļ���ʧ�ܺ�
	}
	fclose(fp);
}