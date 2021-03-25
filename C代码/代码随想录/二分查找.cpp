#include<bits/stdc++.h>
using namespace std;
int erfen_insert(int *a,int b,int left,int right)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if(a[mid]<b)
		{
			left = mid+1;
		}
		else if (a[mid] == b)
		{
			return mid;
		}
		else {
			right = mid;
		}
	}
	return right;
}
int cmp1(int a, int b)
{
	return (a < b);
}
int main()
{
	int a[100];
	srand(time(0));
	for (int i = 0; i < 70;)
	{
		int t = rand() % 1000,key=1;
		for (int j = 0; j < i; j++)
		{
			if (a[j] == t) key = 0;
		}
		if (key)
		{
			a[i] = t;
			i++;
		}
	}
	int b;
	cin >> b;
	sort(a, a + 70,cmp1);
	erfen_insert(a, b,0,70);
	
}