#include<stdio.h>
#include<stdlib.h>
struct way {
	int have;
	int time;
};
typedef struct way way;
int pace(way** w, int n, int s, int t, int min, int ttime)  //传入s-1,t-1
{
	if (ttime >= min)
		return min;
	else if (s == t)
		return ttime;
	for (int i = 0; i < n; i++)
	{
		if (w[s][i].have)
		{
			w[s][i].have = 0;
			w[i][s].have = 0;   //每条路只走一次
			min = pace(w, n, i, t, min, ttime + w[s][i].time);
			w[s][i].have = 1;
			w[i][s].have = 1;
		}
	}
	return min;
}
int main()
{
	way** w;
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	w = (way**)malloc(sizeof(way) * n);
	for (int i = 0; i < n; i++)
	{
		w[i] = (way*)malloc(sizeof(way) * n);
		for (int j = 0; j < n; j++)
		{
			w[i][j].have = 0;
			w[i][j].time = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int j, k;
		scanf("%d%d", &j, &k);
		scanf("%d", &w[j - 1][k - 1].time);
		w[j - 1][k - 1].have = 1;
		w[k - 1][j - 1].have = 1;
		w[k - 1][j - 1].time = w[j - 1][k - 1].time;
	}
	int min = pace(w, n, s - 1, t - 1, 999999, 0);
	printf("%d\n", min);
}