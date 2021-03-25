#include<stdio.h>
#include<stdlib.h>
#define teams 32

void arrange(int num[][teams - 1], int team);

void arrange(int num[][teams - 1], int team)
{
	if (team == 1)
		return;
	else {
		int t = team - 1;                    //比赛队伍
		for (int s = t - 1; s >= 0; s--)          //被比赛队伍
		{
			for (int d = 0; d < teams - 1; d++)     //比赛日期
			{
				if (num[s][d] >= 0 || num[t][d] >= 0)    //判断两队这一天是否有安排
					continue;
				num[s][d] = t;							//被比赛队伍排日程
				num[t][d] = s;							//比赛队伍排日程
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
	for (int i = 0; i < teams; i++)						//所有队伍安排为-1（用于判断）
	{
		for (int j = 0; j < day; j++)
		{
			num[i][j] = -1;
		}
	}
	arrange(num, teams);
	printf("天数");
	for (int i = 1; i < teams; i++)
	{
		printf("%-3d", i);                
	}
	printf("\n");
	for (int i = 0; i < teams; i++)
	{
		printf("%d队:", i + 1);
		for (int j = 0; j < day; j++)
		{
			printf("%-3d", num[i][j] + 1);
		}
		printf("\n");
	}
}