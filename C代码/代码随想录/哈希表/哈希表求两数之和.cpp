#include<bits/stdc++.h>	//数组中两数之和等于target的最优算法
#include<unordered_map>
using namespace std; 
int main()
{
	int num[] = { 2, 7, 11, 15 };
	int target = 26;
	int length = sizeof(num) / sizeof(num[0]);
	unordered_map<int, int>map1;	//哈希表
	for (int i = 0; i < length; i++)
	{
		auto it = map1.find(target - num[i]);	//搜索对应值
		if (it != map1.end())					//有
			printf("%d,%d\n", it->second, i);
		map1[num[i]] = i;						//完善哈希表
	}//数组遍历完成则全部结果出
}