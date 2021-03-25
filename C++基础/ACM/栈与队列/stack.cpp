#include<bits/stdc++.h>
using namespace std;
struct line {
	int a;
	char c;
};
int main()
{
	//stack<map<int,char>>s2;	//map栈
	//stack<line>s1;		//结构体栈
	stack<char>s;	//字符栈
	int a = 5, b = 10, c;
	s.push(a);		//入栈
	s.push(b);		//入栈
	c = s.top();	//	只读栈顶元素
	cout << c << endl;
	s.pop();		//弹栈,无返回值
	s.empty();		//为空返回true，不为空范围false
	s.emplace(20);	//入栈
	while (!(s.empty()))
	{
		c = s.top();
		s.pop();
		cout << c << endl;
	}
}