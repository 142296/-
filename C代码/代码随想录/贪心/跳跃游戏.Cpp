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
	int pre = nums[0];
	for (int i = 1; i < size; i++)
	{
		if (pre == 0)			//能不能继续走
		{
			printf("0");
			return 0;
		}
		pre = max(pre - 1, nums[i]);	//找到能走的最远距离
	}
	printf("1");
}