#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream Infile;
	string a;
	Infile.open("C:\\Users\\14229\\Desktop\\��.txt", ios::binary);	//�����ƶ���
	Infile >> a;					//�ļ�����
	Infile >> a;
	ofstream Outfile;
	Outfile.open("C:\\Users\\14229\\Desktop\\��.txt", ios::app | ios::binary);	//�ļ�β������
	Outfile << "yes";			//�ļ�д
	Outfile.close();
}