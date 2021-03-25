#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
//给定一个大字符串集，和一个小字符串集，要求用大字符串的字符表示出小字符串，不可重复使用
//思路
//用数组(哈希表)记录大字符串每个字符出现次数，然后减去小字符串出现次数，如果某一个小于0则不行
int main()
{
	string small, big;
	cout << "small:";
	cin >> small;
	cout << "big:";
	cin >> big;
	int a[26] = { 0 };
	int blength = big.size();
	int slength = small.size();
	for (int i = 0; i < blength; i++)
	{
		a[big[i] - 'a']++;
	}
	for (int j = 0; j < slength; j++)
	{
		int n = small[j] - 'a';
		a[n]--;
		if (a[n] < 0)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}