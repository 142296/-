//题目http://www.51nod.com/Challenge/ProblemSubmitDetail.html#judgeId=1043204
#include<bits/stdc++.h>
using namespace std;

int W, N;		//N为物品数量，w为背包容量
struct goods {	//存储货物属性的数据类型
	int wei;	//重量
	int val;	//价值
	double per;	//单价
};
struct D {		//优先队列使用的数据类型
	int Max;	//理想最大值
	int now_va;	//现在的价值
	int now_we;	//现在的重量
	int i;		//现在的背包数
	bool operator()(D a, D b)	//优先队列的操作
	{
		return a.Max < b.Max;		//大的在前
	}
};
goods good[102];		
priority_queue<D,vector<D>,D>q1;			//优先队列

bool cmp1(goods a, goods b)		//sort
{
	return a.per > b.per;		//大到小
}
int get_max(int begin,int w,int Max0)	//获取当前成员的理想最大值
{
	for (int i = begin; i < N; i++)
	{
		if (w >= good[i].wei)
		{
			Max0 += good[i].val;
			w -= good[i].wei;
		}
		else
		{
			Max0 += good[i].per * w;
			w = 0;
		}
	}
	return Max0;
}
int main()
{
	cin >> N >> W;
	D now0 = { 0,0,0,0}, now1=now0;
	for (int i = 0; i < N; i++)		//接受输入
	{
		cin >> good[i].wei >> good[i].val;
		good[i].per = good[i].val * 1.0 / good[i].wei;
	}
	sort(good, good + N, cmp1);			//按性价比排序
	//根节点
	q1.push({ get_max(0, W, 0),0,0,0});	//根节点入队
	while (!q1.empty())			//分支限界法
	{
		now0 = now1 = q1.top();
		q1.pop();
		if (now1.i >= N)		//已有结果
			break;
		else			
		{
			//背的情况
			while (now1.i < N && now1.now_we + good[now1.i].wei > W)	//找一个能背的
				now1.i += 1;
			if (now1.i < N)
			{
				now1.now_va += good[now1.i].val;
				now1.now_we += good[now1.i].wei;
			}
			now1.Max = get_max(++now1.i, W - now1.now_we, now1.now_va);	//获取理想最大值
			q1.push(now1);		//背入队
			//不背的情况
			now0.Max = get_max(++now0.i, W - now0.now_we, now0.now_va);	//获取理想最大值
			q1.push(now0);		//不背入队
		}
	}
	printf("%d", now0.now_va);
}