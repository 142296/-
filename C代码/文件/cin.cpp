#include<bits/stdc++.h>
using namespace std;
struct train {
	string train_number;
	string start;
	string destination;
	int start_time;
	int end_time;
	int fare;
	train* next;
};
int main()
{
	FILE* frtrain;
	train a;
	char b[20];
	frtrain = freopen("C:\\Users\\14229\\Desktop\\��.txt", "r", stdin);	//���Դ����׼����
	cin >> a.train_number >> a.start >> a.destination >> a.start_time >> a.end_time >> a.fare;		//cin�Կո�Ϊ��
	cin.get(b, 20);					//��ȡ�̶�������
}