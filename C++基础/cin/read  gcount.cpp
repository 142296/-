#include<iostream>
using namespace std;
int main()
{
	const int SIZE = 50;
	char buf[SIZE];
	cout << "������һ���ı�";
	cin.read(buf, 20);        //ֻ����������20���ַ�
	cout << "�ַ����յ����ַ���Ϊ:"
		<< cin.gcount() << endl;   //����ַ���
	cout << "������ı���:";
	cout << buf;
}