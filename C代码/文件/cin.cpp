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
	frtrain = freopen("C:\\Users\\14229\\Desktop\\火车.txt", "r", stdin);	//用以代替标准输入
	cin >> a.train_number >> a.start >> a.destination >> a.start_time >> a.end_time >> a.fare;		//cin以空格为界
	cin.get(b, 20);					//获取固定数量的
}