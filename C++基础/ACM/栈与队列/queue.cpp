#include<bits/stdc++.h>
using namespace std;
struct line {
	int a;
	char c;
};
int main()
{
	stack<char>q;
	char a = 'a', b = 'b';
	q.push('c');
	q.push(a); q.push(b);	//入队
	a = q.front();			//只读队头
	int size = q.size();	//队内元素个数
	q.pop();				//队头出队
	cout << a<<size<<endl;
	a = q.back();			//只读队尾
	q.empty();				//空返回true
	q.emplace('1');			//入队
	a = q.back();
	cout << a<<endl;
}