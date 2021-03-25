#include<bits/stdc++.h>	//¿ìÂıÖ¸Õë£¬
using namespace std;
int main()
{
	srand(time(0));
	int a[20];
	int i, j;
	for (int i = 0; i < 20; i++)
		a[i] = rand() % 10;
	int del;
	cin >> del;
	for (i = 0, j = 0; i < 20; i++, j++)
	{
		if (a[i] == del)
		{
			i++;
		}
		if (i != j && i < 20)
		{
			a[j] = a[i];
		}
	}
	printf("%d", i - j);
}