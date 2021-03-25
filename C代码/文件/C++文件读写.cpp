#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream Infile;
	string a;
	Infile.open("C:\\Users\\14229\\Desktop\\火车.txt", ios::binary);	//二进制读入
	Infile >> a;					//文件读入
	Infile >> a;
	ofstream Outfile;
	Outfile.open("C:\\Users\\14229\\Desktop\\火车.txt", ios::app | ios::binary);	//文件尾二进制
	Outfile << "yes";			//文件写
	Outfile.close();
}