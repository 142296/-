//题目地址：https://leetcode-cn.com/problems/maximum-subarray/ 
//
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//示例 :
//输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//输出 : 6
//解释 : 连续子数组[4, -1, 2, 1] 的和最大，为 6。
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int Max;
		int* dp = (int*)malloc(sizeof(int) * nums.size());
		fill(dp, dp + nums.size(), -2147483647);
		*dp = max(nums[0], 0);
		Max = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			dp[i] = max(dp[i], max(dp[i - 1], 0) + nums[i]);
			if (dp[i] > Max)
				Max = dp[i];
		}
		return Max;
	}
};
