#include<stdio.h>
#include<iostream>
using namespace std;
int pace(int map[30][30][30], int time, int* s, int l, int r, int c, int min)
{
	if (time >= min)
		return min;
	if (map[s[0]][s[1]][s[2]] == 3)
	{
		min = time;
		return min;
	}
	if (s[0] - 1 >= 0 && map[s[0] - 1][s[1]][s[2]])
	{
		s[0] -= 1;
		if (map[s[0]][s[1]][s[2]] == 1)
			map[s[0]][s[1]][s[2]] = 0;
		min = pace(map, time + 1, s, l, r, c, min);
		if (map[s[0]][s[1]][s[2]] == 0)
			map[s[0]][s[1]][s[2]] = 1;
		s[0] += 1;
	}
	if (s[0] + 1 < l && map[s[0] + 1][s[1]][s[2]])
	{
		s[0] += 1;
		if (map[s[0]][s[1]][s[2]] == 1)
			map[s[0]][s[1]][s[2]] = 0;
		min = pace(map, time + 1, s, l, r, c, min);
		if (map[s[0]][s[1]][s[2]] == 0)
			map[s[0]][s[1]][s[2]] = 1;
		s[0] -= 1;
	}
	if (s[1] - 1 >= 0 && map[s[0]][s[1] - 1][s[2]])
	{
		s[1] -= 1;
		if (map[s[0]][s[1]][s[2]] == 1)
			map[s[0]][s[1]][s[2]] = 0;
		min = pace(map, time + 1, s, l, r, c, min);
		if (map[s[0]][s[1]][s[2]] == 0)
			map[s[0]][s[1]][s[2]] = 1;
		s[1] += 1;
	}
	if (s[1] + 1 < r && map[s[0]][s[1] + 1][s[2]])
	{
		s[1] += 1;
		if (map[s[0]][s[1]][s[2]] == 1)
			map[s[0]][s[1]][s[2]] = 0;
		min = pace(map, time + 1, s, l, r, c, min);
		if (map[s[0]][s[1]][s[2]] == 0)
			map[s[0]][s[1]][s[2]] = 1;
		s[1] -= 1;
	}
	if (s[2] - 1 >= 0 && map[s[0]][s[1]][s[2] - 1])
	{
		s[2] -= 1;
		if (map[s[0]][s[1]][s[2]] == 1)
			map[s[0]][s[1]][s[2]] = 0;
		min = pace(map, time + 1, s, l, r, c, min);
		if (map[s[0]][s[1]][s[2]] == 0)
			map[s[0]][s[1]][s[2]] = 1;
		s[2] += 1;
	}
	if (s[2] + 1 < c && map[s[0]][s[1]][s[2] + 1])
	{
		s[2] += 1;
		if (map[s[0]][s[1]][s[2]] == 1)
			map[s[0]][s[1]][s[2]] = 0;
		min = pace(map, time + 1, s, l, r, c, min);
		if (map[s[0]][s[1]][s[2]] == 0)
			map[s[0]][s[1]][s[2]] = 1;
		s[2] -= 1;
	}
	return min;
}
int main()
{
	int map[30][30][30];
	int l, r, c;
	cin >> l >> r >> c;
	while (l)
	{
		int min = 99999;
		int s[3], e[3];
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
						map[i][j][k] = 2;
						s[0] = i; s[1] = j; s[2] = k;
					}
					else if (ch == 'E')
					{
						map[i][j][k] = 3;
						e[0] = i; e[1] = j; e[2] = k;
					}
				}
			}
		}
		min = pace(map, 0, s, l, r, c, min);
		if (min < 99999)
			printf("Escaped in %d minute(s).\n", min);
		else
			printf("Trapped!\n");
		cin >> l >> r >> c;
	}
}