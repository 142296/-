#include<iostream>
using namespace std;
int main()
{
	int N, i, j, k, key = 0;
	int s[20] = { 0 };
	cin >> N;
	for (i = N; i > 0; i--)
	{
		int mul[20] = { 0 };
		mul[0] = 1;
		for (j = i; j > 0; j--)
		{
			k = 0;
			while (k < 20)
				mul[k++] *= j;
			k = 0;
			while (k < 20)
			{
				if (mul[k] > 9999)
				{
					mul[k + 1] += mul[k] / 10000;
					mul[k] %= 10000;
				}
				k++;
			}
		}
		for (k = 0; k < 20; k++)
		{
			s[k] += mul[k];
			if (s[k] > 9999)
			{
				s[k + 1] += s[k] / 10000;
				s[k] %= 10000;
			}
		}
	}
	for (i = 19; i >= 0; i--)
	{
		if (key)
			printf("%04d", s[i]);
		if (s[i] != 0 && key != 1)
		{
			key = 1;
			printf("%d", s[i]);
		}
	}
}
