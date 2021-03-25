#include<bits/stdc++.h>
#define N 5005
using namespace std;
typedef long long LL;
struct Map {
	int destination;
	int time;
	Map* next;
};
int Dp[N][N];			//动态规划
int vis[N];				//记录是否规划完成
Map map1[N];			//邻接表
int T, n, Maxk;			
void init()
{
	vis[n] = 1;			//终点初始化
	memset(Dp, 0x3f, sizeof Dp);	//按字节赋值，相当于f[n]=0x3f3f3f3f3f3f3f3f
	Dp[n][1] = 0;		//终点初始化
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
			Dp[a][i] = min(Dp[a][i], Dp[d][i-1]+t);		//min(当前值,终点k-1的值+t的值)	因为要保证k值一样，所以终点要取k-1。	
	}
}
int main()
{
	int m;
	cin >> n >> m >> T;
	init();
	for (int i = 0; i < m; i++)			//构成邻接表
	{
		Map* temp;
		Map* link = new Map();
		int a, b, t;
		scanf_s("%d%d%d", &a, &b, &t);
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