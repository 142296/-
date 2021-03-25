//将单词以逆序输出
#include<bits/stdc++.h>
using namespace std;
//翻转单词，去掉首尾空格，单词间只能有一个空格
//花式翻转字符串
int main()
{
	string s = "the sky is blue";
	int size = s.size();
	int j = 0;
	for (int i = 0; i < size;)
	{
		if (i == 0 && s[i] == ' ')			//开始的空格
			while (s[i] == ' ')i++;
		else if (s[i] != ' ')	//非空格
		{
			s[j] = s[i];
			i++; j++;
		}
		else {				//空格
			while (i < size && s[i] == ' ')i++;	//吃掉多个空格
			if (i < size)
			{
				s[j] = ' ';			//留下一个空格
				j++;
			}
		}
	}
	s.resize(j);
	size = j;
	j--;
	for (int i = 0; i <= j; i++, j--)
	{
		if (s[i] != s[j])
		{
			s[i] ^= s[j];
			s[j] ^= s[i];
			s[i] ^= s[j];
		}
	}
	for (int i = 0, j = 0; j < size; )
	{
		while (j < size && s[j] != ' ')
			j++;
		int temp = j + 1;
		j--;
		while (i < j)
		{
			if (s[i] != s[j])
			{
				s[i] ^= s[j];
				s[j] ^= s[i];
				s[i] ^= s[j];
			}
			i++; j--;
		}
		i = temp; j = temp;
	}
	cout << s << endl;
}