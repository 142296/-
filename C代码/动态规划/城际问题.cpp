#include<bits/stdc++.h>
#define N 5005
using namespace std;
typedef long long LL;
struct Map {
	int destination;
	int time;
	Map* next;
};
int Dp[N][N];
int vis[N];
Map map1[N];			//邻接表
int T, n, Maxk;
void init()
{
	vis[n] = 1;			//终点初始化
	memset(Dp, 0x3f, sizeof Dp);	//按字节赋值，相当于f[n]=0x3f3f3f3f3f3f3f3f
	Dp[n][1] = 0;
	for (int i = 0; i <= n; i++)
	{
		map1[i].destination = map1[i].time = 0;
		map1[i].next = NULL;
	}
}
void pace(int a)
{
	if (vis[a]) return;
	vis[a] = 1;
	Map* move = map1[a].next;
	while (move)
	{
		int d = move->destination, t = move->time;
		pace(move->destination);
		move = move->next;
		for (int i = 1; i <= n; i++)			//动态规划  i 表示k
			Dp[a][i] = min(Dp[a][i], Dp[d][i-1]+t);
	}
}
int main()
{
	int m;
	cin >> n >> m >> T;
	init();
	for (int i = 0; i < m; i++)
	{
		Map* temp;
		Map* link = new Map();
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		link->destination = b;
		link->time = t;
		temp = map1[a].next;
		map1[a].next = link;
		link->next = temp;
	}
	pace(1);
	for (int i = n; i >= 0; i--)
	{
		if (Dp[1][i] <= T)
		{
			Maxk = i;
			break;
		}
	}
	printf("%d", Maxk);
}