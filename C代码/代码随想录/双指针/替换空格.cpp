#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s="We are happy.";
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			count++;			//��¼�ո�����
	}
	string n = "%20";
	int sub = n.size() - 1;				//�ո��n�ĳ��Ȳ�
	int size = s.size();
	s.resize(s.size() + count * sub);	//������Ҫ��Ŀռ�
	for (int i = size - 1, j = s.size() - 1; i < j;)//�Ӷ��������ԴӺ���ǰ��������ǰ�����ƶ�Ԫ��
	{
		if (s[i] == ' ')		//�пո񣬻�Ԫ��
		{
			i--;
			for (int k = n.size() - 1; k >= 0; k--, j--)
			{
				s[j] = n[k];
			}
		}
		else {				//�޿ո���Ԫ��
			s[j] = s[i];			
			i--; j--;
		}
	}
	cout << s;
}