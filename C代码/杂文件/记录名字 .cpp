#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i, j, max, min;
	char n[3][10] = { 0 };								//����һ����СΪ3��10�����鴢������
	int g[3];										//�����СΪ3�������鴢��ɼ�
	for (i = 0; i < 3; i++)
	{
		printf("����������");
		for (j = 0; j < 10; j++)								//��¼����
		{
			n[i][j] = getchar();								//��������
			if (n[i][j] == '\n')									//������յ����س���������ѭ��
				break;
		}
		printf("������ɼ�");
		scanf_s("%d", &g[i]);											//���ܳɼ�
		getchar();
	}
	for (i = 0, j = 0; i < 3; i++)
	{
		j = 0;
		while (n[i][j] != '\n')
		{
			printf("%c", n[i][j]);										//����ɼ�
			j++;
		}
		printf("ͬѧ%d��\n", g[i]);										//�������
	}
	max = min = g[0];
	for (i = 1; i < 3; i++)								//��������
	{
		if (g[i] > max)									//�����ֵ
			max = g[i];
		if (g[i] < min)								//����Сֵ
			min = g[i];
	}
	printf("max=%d min=%d", max, min);
}