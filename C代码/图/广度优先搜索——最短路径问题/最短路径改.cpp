#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
struct xy {
	int x, y, z, step;
};
int main()
{
	int map[30][30][30];
	int l, r, c;
	xy start, end;
	cin >> l >> r >> c;
	int move[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0 },{0,0,1},{0,0,-1} };		//移动变量
	while (l)
	{
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					char ch;
					while ((ch = getchar()) == '\n');
					if (ch == '.')
						map[i][j][k] = 1;
					else if (ch == '#')
						map[i][j][k] = 0;
					else if (ch == 'S')
					{
						start.x = i;
						start.y = j;
						start.z = k;
						start.step = 0;
						map[i][j][k] = 1;
					}
					else if (ch == 'E')
					{
						end.x = i;
						end.y = j;
						end.z = k;
						map[i][j][k] = 1;
					}
				}
			}
		}
		queue<xy> q;			//队列
		q.push(start);			//起点入队
		int key = 0;
		while (!q.empty())		//队列非空
		{
			xy temp = q.front();	//队头出
			if (temp.x == end.x && temp.y == end.y && temp.z == end.z)//走到终点
			{
				printf("Escaped in %d minute(s).\n", temp.step);	//输出
				key = 1;			//标志成功
				break;
			}
			q.pop();
			//替换
			for (int i = 0; i < 6; i++)
			{
				if (temp.x + move[i][0] >= 0 && temp.x + move[i][0] < l && temp.y + move[i][1] >= 0 && temp.y + move[i][1] < r &&
					temp.z + move[i][2] >= 0 && temp.z + move[i][2] < c && map[temp.x + move[i][0]][temp.y + move[i][1]][temp.z + move[i][2]])
				{
					xy* link = new xy();
					link->x = temp.x + move[i][0];
					link->y = temp.y + move[i][1];
					link->z = temp.z + move[i][2];
					link->step = temp.step + 1;
					map[link->x][link->y][link->z] = 0;
					q.push(*link);
				}
			}
		}
		if (!key)
			printf("Trapped!\n");
		cin >> l >> r >> c;
	}
}