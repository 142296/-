#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int sum = 0;
	srand(time(0));
	int A[5][5] = { 0 };    //�������ָ�ֵ
	int B[5][5] = { 0 };	//����Ĳ��ֺ�Ϊ0
	int C[5][5] = { 0 };
	printf("A����\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < 3 && j < 4)
			{
				A[i][j] = rand() % 10;
				printf("%d ", A[i][j]);
			}
			B[i][j] = rand() % 10;
		}
		printf("\n");
	}
	printf("B����\n");  //��һ�����B����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", B[i][j]);
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += A[i][k] * B[k][j];
				printf("%d*%d=%d  ", A[i][k], B[k][j], A[i][k] * B[k][j]);
			}
			printf("\n");
			if (sum != 0)
				C[i][j] = sum;
		}
	}
	printf("���");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}