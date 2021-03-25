#include<bits/stdc++.h>       //将两组数合并排序并去重 
using namespace std;
int main()
{
	//multiset与set用法相同，multiset可有重复的key，二者同为红黑树实现
	//unordered_set与set用法相同，unordered_set是无序的哈希表
	set<int>s;
	int n, m;
	cin >> n >> m; 		//分别输出两组数的个数 
	for (int i = 0; i < n + m; i++)
	{
		int num;
		cin >> num;
		s.insert(num);		//set类型只能用insert插入 
	}
	//set<int>::iterator it=s.begin();  定义set<int>类型指针并指向开头 
	//printf("%d",*it);
	set<int>::iterator a;
	a = s.find(2);		//返回下标用指针接收,如果没有返回s.end();
	cout << *a << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		printf("%d ", *it);
	}
	//printf(" \n%d", *(s.find(3))); //查找下标 
	//s.size()				//集合大小
	//erase(1); 			//单个删除
	//erase(a,b);			//群体删除
}