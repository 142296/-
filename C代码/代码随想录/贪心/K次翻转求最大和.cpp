#include<bits/stdc++.h>
//��Ŀ��ַ��https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
//
//����һ���������� A������ֻ�������·����޸ĸ����飺����ѡ��
//ĳ������ i ���� A[i] �滻Ϊ -A[i]��Ȼ���ܹ��ظ�������� K �Ρ�
//�����ǿ��Զ��ѡ��ͬһ������ i����
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
	sort(A, A + size, cmp);		//��С��������
	for (int i = 0; i < size; i++)
	{
		if (A[i] < 0 && K>0)		//�����ĸ�����ʼ�������
		{
			A[i] = -A[i];
			K--;
		}
	}
	if (K % 2)						//ʣ���K����������С��ֵ
		A[size - 1] = -A[size - 1];
	for (int a : A)					//�Ӻ�
		sum += a;
	return 0;
}