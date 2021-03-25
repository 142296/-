https://leetcode-cn.com/problems/gas-station/submissions/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int pre = 0, now = 0, start = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			now += gas[i] - cost[i];
			if (now < 0)
			{
				pre = now + pre;
				now = 0;
				start = i + 1;
			}
		}
		if (now + pre >= 0)
			return start;
		else
			return -1;
	}
};