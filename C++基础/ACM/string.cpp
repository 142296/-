#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin >> a;
	printf("length=%d\n", a.length());	//����
	for (int i = 0; i < a.length(); i++)		//������
	{
		printf("%c", a[i]);
	}
	string b = "1234";
	b.compare("123");  //b�󷵻�1��bС����-1����ȷ���0
	b = a + b;		//ƴ��
	cout << endl << b << endl;
	b.insert(3, "0000");		//0��ʼ ��3������0000
	b.insert(3, 1, 'c');		//����������1��'c'
	cout << b << endl;
	string b1, b2;
	b1 = b2 = b;
	b1.erase(5);		//0��ʼ  ɾ��5֮��
	b2.erase(5, 3);			//0��ʼ  ɾ��5���3��
	cout << "b1:" << b1 << endl;
	cout << "b2:" << b2 << endl;
	b2.append("love");	//
	cout << b2 << endl;
	b2.append("123456789", 5, 3);				//Ҫ��ӵ��ַ��ĵ������ʼ���������;
	cout << b2 << endl;
	b2.append(5, '$');							//Ҫ��ӵ��ַ�n��
	cout << b2 << endl;
}