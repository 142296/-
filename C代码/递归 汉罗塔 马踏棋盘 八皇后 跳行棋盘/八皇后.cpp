#include<stdio.h>
#define side 7
int count = 0;

int check(int chess[][side], int, int);
void set(int, int chess[][side]);
void out(int chess[][side]);                    //�������

int check(int chess[][side], int i, int j)
{
	int k, l;
	for (l = 0; l < side; l++) {                       //�ж���
		if (chess[i][l] && l != j) {
			return 0;
		}
	}
	for (l = 0; l < side; l++)                                 //�ж���
	{
		if (chess[l][j] && l != i)
		{
			return 0;
		}
	}
	for (k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--)                //�ж����Ͻ�
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	for (k = i - 1, l = j + 1; k >= 0 && l < side; k--, l++)                //�ж����Ͻ�
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	for (k = i + 1, l = j - 1; k < side && l >= 0; k++, l--)                //�ж����½�
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	for (k = i + 1, l = j + 1; k < side && l < side; k++, l++)					//�ж����½�
	{
		if (chess[k][l] == 1)
		{
			return 0;
		}
	}
	return 1;
}
void set(int line, int chess[][side])
{
	int row;
	if (line == side)                              //�����㹻����ȣ�������
	{
		out(chess);									//���
	}
	for (row = 0; row < side; row++)                //�ڸ���ĳһ�з�Ů��
	{
		if (check(chess, line, row))				//�жϷ��õĿ�����
		{
			chess[line][row] = 1;
			set(line + 1, chess);
			//����ʧ�ܻ�������
			//һ��һ��������������
			chess[line][row] = 0;
		}
	}
}
void out(int chess[][side])
{
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if (chess[i][j])
				printf("��");
			else
				printf("��");
		}
		printf("\n");
	}
	printf("\n");
	count++;
}
int main()
{
	int chess[side][side] = { 0 };
	set(0, chess);
	printf("%d", count);
}