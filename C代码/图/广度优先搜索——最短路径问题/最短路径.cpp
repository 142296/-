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
						map[i][j][k] = 2;
					}
					else if (ch == 'E')
					{
						end.x = i;
						end.y = j;
						end.z = k;
						map[i][j][k] = 3;
					}
				}
			}
		}
		queue<xy> q;			//����
		q.push(start);			//������
		int key = 0;
		while (!q.empty())		//���зǿ�
		{
			xy temp = q.front();	//��ͷ��
			if (temp.x == end.x && temp.y == end.y && temp.z == end.z)//�ߵ��յ�
			{
				printf("Escaped in %d minutes(s)\n", temp.step);	//���
				key = 1;			//��־�ɹ�
				break;
			}
			q.pop();
			if (temp.x - 1 >= 0 && map[temp.x - 1][temp.y][temp.z])	//̽·
			{
				xy* link = new xy();
				link->x = temp.x - 1;
				link->y = temp.y;
				link->z = temp.z;
				link->step = temp.step + 1;
				map[temp.x - 1][temp.y][temp.z] = 0;
				q.push(*link);
			}
			if (temp.x + 1 < l && map[temp.x + 1][temp.y][temp.z])	//̽·
			{
				xy* link = new xy();
				link->x = temp.x + 1;
				link->y = temp.y;
				link->z = temp.z;
				link->step = temp.step + 1;
				map[temp.x + 1][temp.y][temp.z] = 0;
				q.push(*link);
			}
			if (temp.y - 1 >= 0 && map[temp.x][temp.y - 1][temp.z])	//̽·
			{
				xy* link = new xy();
				link->x = temp.x;
				link->y = temp.y - 1;
				link->z = temp.z;
				link->step = temp.step + 1;
				map[temp.x][temp.y - 1][temp.z] = 0;
				q.push(*link);
			}
			if (temp.y + 1 < r && map[temp.x][temp.y + 1][temp.z])	//̽·
			{
				xy* link = new xy();
				link->x = temp.x;
				link->y = temp.y + 1;
				link->z = temp.z;
				link->step = temp.step + 1;
				map[temp.x][temp.y + 1][temp.z] = 0;
				q.push(*link);
			}
			if (temp.z - 1 >= 0 && map[temp.x][temp.y][temp.z - 1])	//̽·
			{
				xy* link = new xy();
				link->x = temp.x;
				link->y = temp.y;
				link->z = temp.z - 1;
				link->step = temp.step + 1;
				map[temp.x][temp.y][temp.z - 1] = 0;
				q.push(*link);
			}
			if (temp.z + 1 < c && map[temp.x][temp.y][temp.z + 1])	//̽·
			{
				xy* link = new xy();
				link->x = temp.x;
				link->y = temp.y;
				link->z = temp.z + 1;
				link->step = temp.step + 1;
				map[temp.x][temp.y][temp.z + 1] = 0;
				q.push(*link);
			}
		}
		if (!key)
			printf("Trapped!\n");
		cin >> l >> r >> c;
	}
}