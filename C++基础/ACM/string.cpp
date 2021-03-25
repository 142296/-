#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin >> a;
	printf("length=%d\n", a.length());	//长度
	for (int i = 0; i < a.length(); i++)		//可逐项
	{
		printf("%c", a[i]);
	}
	string b = "1234";
	b.compare("123");  //b大返回1，b小返回-1，相等返回0
	b = a + b;		//拼接
	cout << endl << b << endl;
	b.insert(3, "0000");		//0起始 第3个插入0000
	b.insert(3, 1, 'c');		//第三个插入1个'c'
	cout << b << endl;
	string b1, b2;
	b1 = b2 = b;
	b1.erase(5);		//0起始  删除5之后
	b2.erase(5, 3);			//0起始  删除5后的3个
	cout << "b1:" << b1 << endl;
	cout << "b2:" << b2 << endl;
	b2.append("love");	//
	cout << b2 << endl;
	b2.append("123456789", 5, 3);				//要添加的字符的第五个开始，添加三个;
	cout << b2 << endl;
	b2.append(5, '$');							//要添加的字符n次
	cout << b2 << endl;
}