#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double result = sqrt(3.0);
	cout << "�Ը���������С�����0~9λ��";
	for (int i = 0; i <= 9; i++)
	{
		cout.precision(i);   //���µ�������iλ
		cout << result << endl;
	}
	cout << result;
}