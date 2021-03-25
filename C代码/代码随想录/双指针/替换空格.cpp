#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s="We are happy.";
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			count++;			//记录空格数量
	}
	string n = "%20";
	int sub = n.size() - 1;				//空格和n的长度差
	int size = s.size();
	s.resize(s.size() + count * sub);	//加上需要多的空间
	for (int i = size - 1, j = s.size() - 1; i < j;)//加东西，所以从后往前遍历，从前往后移动元素
	{
		if (s[i] == ' ')		//有空格，换元素
		{
			i--;
			for (int k = n.size() - 1; k >= 0; k--, j--)
			{
				s[j] = n[k];
			}
		}
		else {				//无空格，移元素
			s[j] = s[i];			
			i--; j--;
		}
	}
	cout << s;
}