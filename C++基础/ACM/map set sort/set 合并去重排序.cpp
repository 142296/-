#include<bits/stdc++.h>       //���������ϲ�����ȥ�� 
using namespace std;
int main()
{
	//multiset��set�÷���ͬ��multiset�����ظ���key������ͬΪ�����ʵ��
	//unordered_set��set�÷���ͬ��unordered_set������Ĺ�ϣ��
	set<int>s;
	int n, m;
	cin >> n >> m; 		//�ֱ�����������ĸ��� 
	for (int i = 0; i < n + m; i++)
	{
		int num;
		cin >> num;
		s.insert(num);		//set����ֻ����insert���� 
	}
	//set<int>::iterator it=s.begin();  ����set<int>����ָ�벢ָ��ͷ 
	//printf("%d",*it);
	set<int>::iterator a;
	a = s.find(2);		//�����±���ָ�����,���û�з���s.end();
	cout << *a << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		printf("%d ", *it);
	}
	//printf(" \n%d", *(s.find(3))); //�����±� 
	//s.size()				//���ϴ�С
	//erase(1); 			//����ɾ��
	//erase(a,b);			//Ⱥ��ɾ��
}