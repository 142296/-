//���������������
#include<bits/stdc++.h>
using namespace std;
//��ת���ʣ�ȥ����β�ո񣬵��ʼ�ֻ����һ���ո�
//��ʽ��ת�ַ���
int main()
{
	string s = "the sky is blue";
	int size = s.size();
	int j = 0;
	for (int i = 0; i < size;)
	{
		if (i == 0 && s[i] == ' ')			//��ʼ�Ŀո�
			while (s[i] == ' ')i++;
		else if (s[i] != ' ')	//�ǿո�
		{
			s[j] = s[i];
			i++; j++;
		}
		else {				//�ո�
			while (i < size && s[i] == ' ')i++;	//�Ե�����ո�
			if (i < size)
			{
				s[j] = ' ';			//����һ���ո�
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