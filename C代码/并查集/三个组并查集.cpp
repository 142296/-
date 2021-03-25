#include<iostream>
#include<stdio.h>
using namespace std;
int pre[151000] = { 0 };
int find(int x)
{
	int r;
	r = x;
	while (pre[r] != r)
		r = pre[r];
		
	int t;
	while (pre[x] != r)
	{
		t = pre[x];
		pre[x] = r;
		x = t;
	}
	return r;
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		pre[a] = b;
}
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= 3 * n; i++)	pre[i] = i;
	int mistake=0;
	while (k--)
	{
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		if (b < 1 || b > n || c < 1 || c>n)		//超限
		{
			mistake++;
			continue;
		}
		if (a == 1)						//1
		{
			if (find(b) == find(c + n) || find(b) == find(c + 2 * n))//不是同种
				mistake++;
			else 
			{
				unite(b, c);		//同为第一种
				unite(b + n, c + n);		//同为第二种
				unite(b + 2 * n, c + 2 * n);	//同为第三种
			}
		}
		else						//2
		{
			if (find(b) == find(c) || find(b) == find(c + 2 * n))//b、c同种或c克b则不对
				mistake++;
			else {			//b克c即可
				unite(b, c + n);		
				unite(b + n, c + 2 * n);
				unite(b + 2 * n, c);
			}
		}
	}
	cout << mistake << endl;
}