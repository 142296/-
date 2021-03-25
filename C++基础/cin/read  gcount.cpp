#include<iostream>
using namespace std;
int main()
{
	const int SIZE = 50;
	char buf[SIZE];
	cout << "请输入一段文本";
	cin.read(buf, 20);        //只保留缓存区20个字符
	cout << "字符串收到的字符数为:"
		<< cin.gcount() << endl;   //获得字符数
	cout << "输入的文本是:";
	cout << buf;
}