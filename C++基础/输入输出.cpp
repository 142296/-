#include <iostream>
using namespace std; 	 //引用命名空间
int add(int a, int b)
{
    return a + b;
}
int main()
{
    int six,seven;
    cin >> six>>seven;
    cout << add(1, 5)<<endl;       //end of line 输出一个换行符
    cout << "Hello World!"<<six<<seven<<"Hi!";
}
