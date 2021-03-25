#include<bits/stdc++.h>
//题目链接：https://leetcode-cn.com/problems/jump-game/
//
//给定一个非负整数数组，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个位置。
using namespace std;
int main()
{
	int nums[] = { 2,3,1,1,4 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int cover = 0;
	for (int i = 0; i <= cover; i++)
	{
		cover = max(cover, nums[i] + i);//找到覆盖的最远
		if (cover >= size - 1)		//能到终点
			return 1;
	}
	return 0;
}