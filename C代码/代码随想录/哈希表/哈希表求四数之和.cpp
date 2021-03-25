#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
unordered_map<int, int>m1;
//题目：  四个数组，每个数组选一个数，求相加为0的个数
//思路：  1.首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
//2.遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
//3.定义int变量count，用来统计a + b + c + d = 0 出现的次数。
//4.在遍历大C和大D数组，找到如果 0 - (c + d) 在map中出现过的话，
//就用count把map中key对应的value也就是出现次数统计出来。
int main()
{
	srand(time(0));
	int a[10], b[10], c[10], d[10];
	for (int i = 0; i < 10; i++)
	{
		int flag = rand() % 2 ? 1 : -1;
		a[i] = flag * rand() % 10;
		flag = rand() % 2 ? 1 : -1;
		b[i] = flag * rand() % 10; 
		flag = rand() % 2 ? 1 : -1;
		c[i] = flag * rand() % 10; 
		flag = rand() % 2 ? 1 : -1;
		d[i] = flag * rand() % 10;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int n = a[i] + b[j];
				m1[n]++;
		}
	}
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int n = c[i] + d[j];
			count += m1[-n];
		}
	}
	cout << count;
}