#include<stdio.h>
#include<stdlib.h>
#define teams 32

void arrange(int num[][teams - 1], int team);

void arrange(int num[][teams - 1], int team)
{
	if (team == 1)
		return;
	else {
		int t = team - 1;                    //��������
		for (int s = t - 1; s >= 0; s--)          //����������
		{
			for (int d = 0; d < teams - 1; d++)     //��������
			{
				if (num[s][d] >= 0 || num[t][d] >= 0)    //�ж�������һ���Ƿ��а���
					continue;
				num[s][d] = t;							//�������������ճ�
				num[t][d] = s;							//�����������ճ�
				break;
			}
		}
	}

	arrange(num, team - 1);
}

int main()
{
	const int day = teams - 1;
	int num[teams][day];
	for (int i = 0; i < teams; i++)						//���ж��鰲��Ϊ-1�������жϣ�
	{
		for (int j = 0; j < day; j++)
		{
			num[i][j] = -1;
		}
	}
	arrange(num, teams);
	printf("����");
	for (int i = 1; i < teams; i++)
	{
		printf("%-3d", i);                
	}
	printf("\n");
	for (int i = 0; i < teams; i++)
	{
		printf("%d��:", i + 1);
		for (int j = 0; j < day; j++)
		{
			printf("%-3d", num[i][j] + 1);
		}
		printf("\n");
	}
}