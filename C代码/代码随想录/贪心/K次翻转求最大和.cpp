#include<bits/stdc++.h>
//题目地址：https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
//
//给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择
//某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。
//（我们可以多次选择同一个索引 i。）
using namespace std;
int cmp(int a, int b)
{
	return abs(a) > abs(b);
}
int main()
{
	int sum = 0;
	int A[] = { 3,-1,0,2 };
	int K = 3;
	int size = sizeof(A) / sizeof(A[0]);
	sort(A, A + size, cmp);		//从小到大排序
	for (int i = 0; i < size; i++)
	{
		if (A[i] < 0 && K>0)		//从最大的负数开始变成正数
		{
			A[i] = -A[i];
			K--;
		}
	}
	if (K % 2)						//剩余的K用来更改最小的值
		A[size - 1] = -A[size - 1];
	for (int a : A)					//加和
		sum += a;
	return 0;
}