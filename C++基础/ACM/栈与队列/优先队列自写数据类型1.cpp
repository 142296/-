#include<bits/stdc++.h>		//自写数据类型
using namespace std;
struct S{				//重写仿函数
	int max;
	int da;
	bool operator()(S a, S b)
	{
		return a.max < b.max;		//大顶堆
	}
};
priority_queue<S,vector<S>,S>q1;
int main()
{
	S a;
	a = { 5,3 };
	q1.push(a);
	a = { 4,4 };
	q1.push(a);
	a = { 6,6 };
	q1.push(a);
	q.top();
}