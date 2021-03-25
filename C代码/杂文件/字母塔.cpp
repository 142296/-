#include<bits\stdc++.h>
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j < n; j++)
			printf(" ");
		for (int k = 0; k < i * 2 - 1; k++)
		{
			if (k < i)
				printf("%c", 'A' + i - k - 1);
			else
				printf("%c", 'A' + k % i + 1);
		}
		printf("\n");
	}
}