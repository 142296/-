#include<bits/stdc++.h>	//�������ڣ�
using namespace std;//����һ������ n ���������������һ�������� s ��
				//�ҳ���������������� �� s �ĳ�����С�����������飬�������䳤��
int main()
{
	srand(time(0));
	int a[20];
	int i, j;
	for (int i = 0; i < 20; i++)
		a[i] = rand() % 10;
	int sum, count = 20;
	cin >> sum;
	sum -= a[0];
	for (i = 0, j = 0; i < 20 || sum <= 0;)
	{
		if (sum > 0)
		{
			i++;
			if (i < 20);
			sum -= a[i];
		}
		if (sum <= 0)
		{
			if (i - j + 1 < count)
				count = i - j + 1;
			sum += a[j];
			j++;
		}
	}
	printf("%d", count);
}