#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
					//数据类型   容器类型  方法
	//	priority_queue<int,vector<int>,greater<int> >a;		//升序
	priority_queue<int,vector<int>,less<int>  >a;		//降序
	for (int i = 0; i < 100; i++)		//保存为二叉排序树
	{	
		a.push(rand() % 100);
	}
	while (!a.empty())
	{
		cout << a.top() << ' ';
		a.pop();
	}
	priority_queue<pair<int, int> >a;
	pair<int, int> b(1, 2);
	pair<int, int> c(1, 3);
	pair<int, int> d(2, 5);
	a.push(b);
	a.push(c);
	a.push(d);
	while (!a.empty())
	{
		cout << a.top().first << ' ' << a.top().second << endl;
		a.pop();
	}
}