#include<bits/stdc++.h>
//题目地址：https://leetcode-cn.com/problems/jump-game-ii/
//
//给定一个非负整数数组，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//你的目标是使用最少的跳跃次数到达数组的最后一个位置。
using namespace std;
int main()
{
	int nums[] = {2,1};
	int size = sizeof(nums) / sizeof(nums[0]);
	int Max = nums[0],pre=Max,count=1,key=1;	//默认已经跳了
	for (int i = 1; i < size; i++)
	{
		key = 0;
		pre--;
		Max = max(Max - 1, nums[i]);
		if (!pre)			//前一个走到头
		{
			count++;
			pre = Max;
			key = 1;		//默认跳过了，这里又跳，所以用key剪掉
		}
	
	}
	printf("%d",count-key);
}